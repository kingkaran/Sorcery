#include "novicepyromancer.h"
using namespace std;

NovicePyromancer::NovicePyromancer(shared_ptr<Card> s, Player *owner):
Minion("Novice Pyromancer","","Minion",owner,1,0,1,nullptr,nullptr){
	activatedAb = s;
	abilityCost = 1;
}

NovicePyromancer::~NovicePyromancer(){}

void NovicePyromancer::activateAction(std::shared_ptr<Card> c) {
	if(actionCharge > 0){
		actionCharge -=1 ;
		activatedAb->activateAction(c);
	}
}
	
void NovicePyromancer::activateTrigger(Event e) {}

int NovicePyromancer::getAbCost(){
	return abilityCost;
}
