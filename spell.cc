#include "card.h"
#include "spell.h"
#include "player.h"
using namespace std;

Spell::Spell(std::string name, std::string desc, std::string type, int cost, Player *owner):
   Card(name, desc, type, cost, owner){}

Spell::~Spell(){}

int Spell::getAttack() const {}

void Spell::attack(shared_ptr<Card> c)  {}

void Spell::attack(Player *p) {}

int Spell::getDefence()const {}

int Spell::getActionCharge()const{}

void Spell::setActionCharge(int i) {}

void Spell::inspect() {}

void Spell::beAttacked(int i){}

void Spell::popEnchant(){}

void Spell::setAttack(int i){}

void Spell::getEffect(){}

void Spell::setDefence(int i){}

void Spell::addEnchant(shared_ptr<Card> c) {}

void Spell::setHost(Card * c) {}

void Spell::setBlockAbility(bool b) {}

int Spell::getRitualCharge() const {return 0;}

int Spell::getAbCost(){
	return 0;
}

void Spell::setRitualCharge(int i) {}

int Spell::getRitualCost(){
	return 0;
}

shared_ptr<Card> Spell::getActivatedAb(){
	return nullptr;
}

shared_ptr<Card> Spell::getTriggeredAb(){
	return nullptr;
}

vector<shared_ptr<Card>> Spell::getEnchants(){
	vector<shared_ptr<Card>> v;
	return v;
}

bool Spell::abBlocked(){
	return false;
}
