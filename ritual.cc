#include "ritual.h"
#include "triggeredAbility.h"
#include "player.h"

Ritual::Ritual(std::string name, std::string desc,
 std::string type, int cost, Player *owner, int initChrg, int costChrg): 
TriggeredAbility(name, desc, type, cost, owner), initCharge{initChrg},costCharge{costChrg} {}

Ritual::~Ritual(){}

int Ritual::getRitualCharge() const{
	return initCharge;
}

void Ritual::setRitualCharge(int i){
	initCharge = i;
}
int Ritual::getRitualCost(){
	return costCharge;
}
