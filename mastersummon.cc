#include "mastersummon.h"
#include "player.h"
using namespace std;
MasterSummoner::MasterSummoner(shared_ptr<Card> s, Player *owner):
Minion("Master Summoner","","Minion",owner,3,2,3,s,nullptr){
	abilityCost = 2;
}

MasterSummoner::~MasterSummoner(){}

void MasterSummoner::activateAction(std::shared_ptr<Card> c) {
	if(actionCharge > 0){
		activatedAb->activateAction(c);
		actionCharge -= 1;
	}
}
	
void MasterSummoner::activateTrigger(Event e) {}

int MasterSummoner::getAbCost(){
	return abilityCost;
}
