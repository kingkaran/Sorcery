#include "airelement.h"
#include "minion.h"
#include "player.h"

AirElemental::AirElemental(Player *owner):
Minion("Air Elemental","","Minion",owner,0,1,1,nullptr,nullptr){
}

AirElemental::~AirElemental(){}

void AirElemental::activateAction(std::shared_ptr<Card> c){}
void AirElemental::activateTrigger(Event e){}
