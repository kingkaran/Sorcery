#include "apprsummon.h"
#include "player.h"

using namespace std;

ApprenticeSummoner::ApprenticeSummoner(shared_ptr<Card> s, Player *owner):
Minion("Apprentice Summoner","","Minion",owner,1,1,1,s,nullptr){
	abilityCost = 1;
}

ApprenticeSummoner::~ApprenticeSummoner(){}

void ApprenticeSummoner::activateAction(std::shared_ptr<Card> c) {
	if(actionCharge > 0){
		activatedAb->activateAction(c);
		actionCharge -= 1;
	}
}
	
void ApprenticeSummoner::activateTrigger(Event e) {}

int ApprenticeSummoner::getAbCost(){
	return abilityCost;
}
