#include "auraofpower.h"
#include "card.h"
#include "event.h"

AuraOfPower::AuraOfPower(Player *owner):
Ritual("Aura of Power", "Whenever a minion enters play under your control, it gains +1/+1","Ritual", 1, owner, 4,1){}

AuraOfPower::~AuraOfPower(){}

void AuraOfPower::activateAction(std::shared_ptr<Card>c){
}

void AuraOfPower::activateTrigger(Event e){
}
