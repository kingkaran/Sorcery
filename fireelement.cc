#include "fireelement.h"
#include "player.h"

using namespace std;

FireElemental::FireElemental(shared_ptr<Card> s, Player *owner):
Minion("Fire Elemental","","Minion",owner,2,2,2,nullptr,nullptr){
	triggeredAb = s;
}

FireElemental::~FireElemental(){}

void FireElemental::activateAction(std::shared_ptr<Card> c) {}

void FireElemental::activateTrigger(Event e) {
	triggeredAb->activateTrigger(e);
}

