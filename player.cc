#include <string>
#include "player.h"
#include "deck.h"
#include "prompt.h"
#include "ritual.h"
#include "board.h"
#include "minion.h"
#include "enchantdec.h"
#include "airelement.h"
#include "event.h"
#include <iostream>

using namespace std;

Player::Player(string name, Deck *d, Board *b, int num, bool testing){
	hp = 20;
	magic = 3;
	this->name = name;
	deck = d;
	currentBoard = b;
	playerNum = num;
	testMode = testing;
}

//since hand has cards from deck, as well as graveyard, only delete
//on deck is needed.
Player::~Player(){}

bool Player::isDead()const{
	if(hp <= 0){
		return true;
	}
	return false;
}

Board * Player::getCurrentBoard(){
	return currentBoard;
}

void Player::dealDamage(int i){
	if(activeMinions.size() > 0){
		for(int j = activeMinions.size() - 1; j >= 0; --j){
			activeMinions[j]->beAttacked(i);
		}
	}
}

vector<shared_ptr<Card>> Player::getGrave()const{
	return graveyard;
}

void Player::drawFive(){
	for(int i = 0; i < 5; ++i){
		hand.emplace_back(deck->topCard());
	}
}

void Player::setRitual(shared_ptr<Card> c){
	activeRitual = c;
}

void Player::playCard(int i){
	shared_ptr<Card> temp = hand[i-1];
	if(magic >= temp->getCost() || testMode){
		if(temp->getType() == "Minion"){
			if(activeRitual != nullptr){
				if(activeRitual->getName() == "Standstill"){
					int charge = activeRitual->getRitualCharge();
					if(charge >= activeRitual->getRitualCost()){
						activeRitual->setRitualCharge(activeRitual->getRitualCharge() - activeRitual->getRitualCost());
						sendToGrave(temp);
						killCard(temp);
					}else{
						play(temp);
					}
				}else{
					if(currentBoard->getInactive()->getRitual() != nullptr){
						if(currentBoard->getInactive()->getRitual()->getName() == "Standstill"){
							int charge = currentBoard->getInactive()->getRitual()->getRitualCharge();
							shared_ptr<Card> rit = currentBoard->getInactive()->getRitual();
							if(charge >= rit->getCost()){
								rit->setRitualCharge(rit->getRitualCharge() - rit->getRitualCost());
								sendToGrave(temp);
								killCard(temp);
							}else{
								play(temp);
							}
						}else{
							play(temp);
						}
					}else{
						play(temp);
					}
				}
			}else{
				if(currentBoard->getInactive()->getRitual() != nullptr){
					if(currentBoard->getInactive()->getRitual()->getName() == "Standstill"){
						int charge = currentBoard->getInactive()->getRitual()->getRitualCharge();
						shared_ptr<Card> rit = currentBoard->getInactive()->getRitual();
						if(charge >= rit->getCost()){
							rit->setRitualCharge(rit->getRitualCharge() - rit->getRitualCost());
							sendToGrave(temp);
							killCard(temp);
						}else{
							play(temp);
						}
					}else{
						play(temp);
					}
				}else{
					play(temp);
				}
			}
		}else{
			play(temp);
		}
	}else{
		Prompt p;
		p.magicError();
	}
}

void Player::play(shared_ptr<Card> m){
	if(m->getType() == "Minion"){
		if(activeRitual != nullptr){
			if(activeRitual->getName() == "Aura of Power"){
				int charge = activeRitual->getRitualCharge();
				if(charge >= activeRitual->getRitualCost()){
					activeRitual->setRitualCharge(activeRitual->getRitualCharge() - activeRitual->getRitualCost());
					m->setAttack(m->getAttack() + 1);
					m->setDefence(m->getDefence() + 1);
				}
			}
		}
		addMinion(m,true);
	}else if(m->getType() == "Ritual"){
		activeRitual = m;
		killCard(m);
	}else{
		if(m->getName() == "Raise Dead"){
			if(activeMinions.size() < 5){
				if(graveyard.size() > 0){
					m->activateAction(graveyard.back());
				}
			}
		}else if(m->getName() == "Recharge"){
			m->activateAction(activeRitual);
		}else{
			m->activateAction(nullptr);
		}
	}
}

void Player::playCard(int i, int p, int t){
	Player *targetPlay = nullptr;
	if(p == playerNum)
		targetPlay = currentBoard->getActive();
	else
		targetPlay = currentBoard->getInactive();

	if(magic >= hand[i-1]->getCost() || testMode){
		if(magic < hand[i-1]->getCost()){
			magic = 0;
		}
		if(hand[i-1]->getType() == "Spell"){
			shared_ptr<Card> temp = hand[i-1];
			if(t >= 1 && t <= 5){
				vector<shared_ptr<Card>> c = targetPlay->getActiveMinions();
				play(temp, c[t-1]);
			}
		}else if(hand[i-1]->getType() == "Enchantment"){
			shared_ptr<Card> temp = hand[i-1];
			if(t>=1 && t<=5){
				vector<shared_ptr<Card>> c = targetPlay->getActiveMinions();
				if(c.size() > t - 1){
					play1(temp, c[t-1]);
				}
			}else{
				shared_ptr<Card> temp1 = targetPlay->getRitual();
				play1(temp, temp1);
			}
		}
	}else{
		Prompt p;
		p.magicError();
	}
}

bool Player::getTest(){
	return testMode;
}

void Player::removeCard(shared_ptr<Card> c){
	if(hand.size() == 5){
		for(int i = 0; i < activeMinions.size(); ++i){
			if(activeMinions[i] == c)
				activeMinions.erase(activeMinions.begin()+i);
		}
	}else{
		hand.emplace_back(c);
		for(int i = 0; i < activeMinions.size(); ++i){
			if(activeMinions[i] == c)
				activeMinions.erase(activeMinions.begin()+i);
		}
	}
}

void Player::killCard(shared_ptr<Card> c){
	if(magic < c->getCost() && testMode){
		magic = 0;
	}else{
		magic -= c->getCost();
	}
	for(int i = 0; i < hand.size(); ++i){
		if(hand[i] == c){
			hand.erase(hand.begin()+i);
		}
	}
}

void Player::play(shared_ptr<Card> s, shared_ptr<Card> c){
	if(s->getName() == "Banish"){
		if(c->getType() == "Ritual"){
			c->getOwner()->setRitual(nullptr);
		}else{
			s->activateAction(c);
		}
	}else{
		s->activateAction(c);
	}
}

void Player::play1(shared_ptr<Card> e, shared_ptr<Card> c){
	c->addEnchant(e);
}

int Player::getHP()const{
	return hp;
}

int Player::getMagic()const{
	return magic;
}

vector<shared_ptr<Card>> Player::getHand()const{
	return hand;
}

void Player::setMagic(int m){
	magic = m;
}

string Player::getName()const{
	return name;
}

//draw() returns true if a draw is successful, false otherwise
void Player::draw(){
	hand.emplace_back(deck->topCard());
}

void Player::takeTurn(){
	magic += 1;
	if(hand.size() < 5){
		draw();
	}
	for(int i = 0; i < activeMinions.size(); ++i){
		activeMinions[i]->setActionCharge(1);
		if(activeMinions[i]->getEnchants().size() > 0){
			for(int j = 0; j < activeMinions[i]->getEnchants().size(); ++j){
				if(activeMinions[i]->getEnchants()[j]->getName() == "Haste"){
					activeMinions[i]->getEnchants()[j]->getEffect();
				}
			}
		}
	}
	if(activeRitual != nullptr){
		activeRitual->activateTrigger(Event::StartOfTurn);
	}
}

void Player::endTurn(){
	for(int i = 0; i < activeMinions.size(); ++i){
		if(activeMinions[i]->getTriggeredAb() != nullptr){
			if(!activeMinions[i]->abBlocked()){
				activeMinions[i]->activateTrigger(Event::EndOfTurn);
			}
		}
	}
}

void Player::setDeck(Deck *d){
	deck = d;
}

Deck *Player::getDeck()const{
	return deck;
}

shared_ptr<Card> Player::getMinion(int i) const{
	return hand[i];
}

vector<shared_ptr<Card>> Player::getActiveMinions() const{
	return activeMinions;
}

shared_ptr<Card> Player::getRitual() const{
	return activeRitual;
}

void Player::setHP(int h){
	hp = h;
}

void Player::attack(int i){
	Player *p = currentBoard->getInactive();
	shared_ptr<Card> m = activeMinions[i-1];
	m->attack(p);
}

void Player::attack(int i, int j){
	Player *p = currentBoard->getInactive();
	shared_ptr<Card> minAct = activeMinions[i-1];
	shared_ptr<Card> minInact = p->getActiveMinions()[j-1];
	minAct->attack(minInact);
}

void Player::addMinion(shared_ptr<Card> m, bool fromHand){
	bool dead = false;
	if(activeMinions.size() < 5){
		auto v = currentBoard->getInactive()->getActiveMinions();
		for(int i = 0; i < v.size(); ++i){
			if(v[i]->getTriggeredAb() != nullptr){
				if(v[i]->getName() == "Fire Elemental" && !v[i]->abBlocked()){
					m->setDefence(m->getDefence() - 1);
					if(m->getDefence() <= 0){
						sendToGrave(m);
						dead = true;
					}
				}else{
					v[i]->activateTrigger(Event::MinionEnters);
				}
			}
		}
		if(!dead){
			activeMinions.emplace_back(m);
		}
		if(fromHand){
			killCard(m);
		}
	}
}


void Player::sendToGrave(shared_ptr<Card> c){
	if(c->getEnchants().size() > 0){
		for(int i = 0; i < c->getEnchants().size(); ++i){
			c->popEnchant();
		}
	}
	for(int i = 0; i < activeMinions.size(); ++i){
		if(activeMinions[i] == c){
			activeMinions.erase(activeMinions.begin()+i);
		}
	}
	graveyard.emplace_back(c);
	vector<shared_ptr<Card>> v1 = currentBoard->getP1()->getActiveMinions();
	for(int i = 0; i < v1.size(); ++i){
		if(v1[i]->getTriggeredAb() != nullptr){
			v1[i]->activateTrigger(Event::MinionLeaves);
		}
	}
	vector<shared_ptr<Card>> v = currentBoard->getP2()->getActiveMinions();
	for(int i = 0; i < v.size(); ++i){
		if(v[i]->getTriggeredAb() != nullptr){
			v[i]->activateTrigger(Event::MinionLeaves);
		}
	}
}


bool Player::revive(shared_ptr<Card> c){
	if(activeMinions.size() < 5 || graveyard.size() > 0){
		if(activeRitual != nullptr){
			if(activeRitual->getName() == "Standstill"){
				int charge = activeRitual->getRitualCharge();
				if(charge >= activeRitual->getRitualCost()){
					activeRitual->setRitualCharge(activeRitual->getRitualCharge() - activeRitual->getRitualCost());
				}
			}else{
				if(currentBoard->getInactive()->getRitual() != nullptr){
					if(currentBoard->getInactive()->getRitual()->getName() == "Standstill"){
						int charge = currentBoard->getInactive()->getRitual()->getRitualCharge();
						shared_ptr<Card> rit = currentBoard->getInactive()->getRitual();
						if(charge >= rit->getCost()){
							rit->setRitualCharge(rit->getRitualCharge() - rit->getRitualCost());
						}else{
							activeMinions.emplace_back(c);
							graveyard.pop_back();
							return true;
						}
					}else{
						activeMinions.emplace_back(c);
						graveyard.pop_back();
						return true;
					}
				}else{
					activeMinions.emplace_back(c);
					graveyard.pop_back();
					return true;
				}
			}
		}else{
			if(currentBoard->getInactive()->getRitual() != nullptr){
				if(currentBoard->getInactive()->getRitual()->getName() == "Standstill"){
					int charge = currentBoard->getInactive()->getRitual()->getRitualCharge();
					shared_ptr<Card> rit = currentBoard->getInactive()->getRitual();
					if(charge >= rit->getCost()){
						rit->setRitualCharge(rit->getRitualCharge() - rit->getRitualCost());
					}else{
						activeMinions.emplace_back(c);
						graveyard.pop_back();
						return true;
					}
				}else{
					activeMinions.emplace_back(c);
					graveyard.pop_back();
					return true;
				}
			}else{
				activeMinions.emplace_back(c);
				graveyard.pop_back();
				return true;
			}
		}
	}
	return false;
}

void Player::use(int i){
	if(activeMinions[i-1]->getActivatedAb() == nullptr){
		Prompt p;
		p.noAct();
	}else{
		if(!activeMinions[i-1]->abBlocked()){
			if(activeMinions[i-1]->getActionCharge() >= 1){
				activeMinions[i-1]->activateAction(nullptr);
			}
		}
	}
}

void Player::use(int i, int t, int tc){
	Player *targ = nullptr;
	if(t == 2){
		targ = currentBoard->getP2();
	}else{
		targ = currentBoard->getP1();
	}
	if(!activeMinions[i-1]->abBlocked() &&
	 (activeMinions[i-1]->getActivatedAb() != nullptr)){
		if(activeMinions[i-1]->getActionCharge() >= 1){
			activeMinions[i-1]->activateAction(targ->activeMinions[tc - 1]);
		}
	}
}

void Player::inspect(int i){
	activeMinions[i-1]->inspect();
}

