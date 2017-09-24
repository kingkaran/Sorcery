#include "standstill.h"
#include "card.h"
#include "event.h"

Standstill::Standstill(Player *owner):
Ritual("Standstill", "whenever a minion enters play, destroy it","Ritual", 3, owner, 4, 2){}

Standstill::~Standstill(){}

void Standstill::activateAction(std::shared_ptr<Card> c){}

void Standstill::activateTrigger(Event e){}
