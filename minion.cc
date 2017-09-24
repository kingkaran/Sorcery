#include "card.h"
#include "minion.h"
#include "player.h"
#include "spell.h"
#include "prompt.h"
#include <iostream>
using namespace std;

Minion::Minion(string name, string desc, string type, Player *owner,
		int cost, int atk, int def, shared_ptr<Card> active, shared_ptr<Card> trigger):
		Card(name,desc,type,cost, owner),
		att{atk},def{def},activatedAb{active},triggeredAb{trigger}{
	actionCharge = 0;
	abilityBlocked = false;
}

Minion::~Minion(){}

int Minion::getAttack()const{
	return att;
}

int Minion::getRitualCharge() const {}

void Minion::setRitualCharge(int i){}

int Minion::getAbCost(){
	return 0;
}

void Minion::popEnchant(){
	if(enchants.back()->getName() == "Giant Strength"){
		att -= 2;
		def -= 2;
		if(def <= 0){
			def = 1;
		}
	}else if(enchants.back()->getName() == "Enrage"){
		att = att / 2;
		def = def / 2;
		if(def <= 0){
			def = 1;
		}
		if(att <= 0){
			att = 1;
		}
	}else if(enchants.back()->getName() == "Magic Fatigue"){
		activatedAb->setCost(activatedAb->getCost() - 2);
	}
	enchants.pop_back();
}

vector<shared_ptr<Card>> Minion::getEnchants(){
	return enchants;
}

shared_ptr<Card> Minion::getActivatedAb(){
	return activatedAb;
}

shared_ptr<Card> Minion::getTriggeredAb(){
	return triggeredAb;
}

bool Minion::abBlocked(){
	return abilityBlocked;
}

void Minion::attack(shared_ptr<Card> m){
	if(actionCharge > 0){
		actionCharge -= 1;
		m->beAttacked(att);
		int attMinion = m->getAttack();
		def -= attMinion;
		if(def <= 0){
			owner->sendToGrave(shared_from_this());
		}
	}
	
}

void Minion::setAttack(int i){
	att = i;
}

void Minion::attack(Player *p){
	if(actionCharge > 0){
		actionCharge -= 1;
		int hp = p->getHP() - att;
		p->setHP(hp);
	}
}

void Minion::beAttacked(int i){
	def -= i;
	if(def <= 0){
		owner->sendToGrave(shared_from_this());
	}
}

int Minion::getRitualCost(){
	return 0;
}

int Minion::getDefence()const {
	return def;
}

void Minion::activateAction(shared_ptr<Card> c){
	if(!abilityBlocked && actionCharge > 0){
		actionCharge -= 1;
		activatedAb->activateAction(shared_from_this());
	}
}

void Minion::activateTrigger(Event e){
	if(!abilityBlocked){
		triggeredAb->activateTrigger(e);
	}
}

int Minion::getActionCharge()const{
	return actionCharge;
}

void Minion::setActionCharge(int i){
	actionCharge = i;
}

void Minion::inspect(){
	Prompt p;
	p.inspectMinion(this);
}

void Minion::getEffect(){
	for(auto &n:enchants){
		n->getEffect();
	}
}

void Minion::setDefence(int i){
	def = i;
}

void Minion::addEnchant(shared_ptr<Card> c) {
	c->setHost(this);//shared_from_this());
	c->getEffect();
	enchants.emplace_back(c);
	owner->killCard(c);
}

void Minion::setHost(Card * c) {}

void Minion::setBlockAbility(bool b){
	abilityBlocked = b;
}
