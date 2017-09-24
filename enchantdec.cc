#include "enchantdec.h"
using namespace std;

EnchantDec::EnchantDec(string name, string desc,
         string type, int cost, Player *owner):
	Card(name, desc, type, cost, owner) {
		hostMinion = nullptr;
}

EnchantDec::~EnchantDec(){}

void EnchantDec::setHost(Card *c){//shared_ptr<Card> c){
	hostMinion = c;
}

int EnchantDec::getAttack() const {}

void EnchantDec::attack(shared_ptr<Card> c)  {}

void EnchantDec::attack(Player *p) {}

int EnchantDec::getDefence()const {}

int EnchantDec::getActionCharge()const{}

void EnchantDec::setActionCharge(int i) {}

void EnchantDec::inspect() {}

void EnchantDec::beAttacked(int i){}

void EnchantDec::popEnchant(){}

void EnchantDec::setAttack(int i){}

void EnchantDec::getEffect(){}

void EnchantDec::setDefence(int i){}

void EnchantDec::addEnchant(shared_ptr<Card> c) {}

void EnchantDec::setBlockAbility(bool b) {}

int EnchantDec::getRitualCharge() const {return 0;}

void EnchantDec::setRitualCharge(int i) {}

void EnchantDec::activateAction(std::shared_ptr<Card> c) {}

void EnchantDec::activateTrigger(Event e) {}

int EnchantDec::getRitualCost(){
	return 0;
}

int EnchantDec::getAbCost(){
	return 0;
}

shared_ptr<Card> EnchantDec::getActivatedAb(){
	return nullptr;
}

shared_ptr<Card> EnchantDec::getTriggeredAb(){
	return nullptr;
}

vector<shared_ptr<Card>> EnchantDec::getEnchants(){
	vector<shared_ptr<Card>> v;
	return v;
}
bool EnchantDec::abBlocked(){
	return false;
}
