#include "darkritual.h"
#include "card.h"
#include "event.h"
#include "player.h"
using namespace std;

DarkRitual::DarkRitual(Player *owner):
Ritual("Dark Ritual", "At the start of your turn, gain 1 magic","Ritual", 0, owner, 5,1){}

DarkRitual::~DarkRitual(){}

void DarkRitual::activateAction(shared_ptr<Card> c){}

void DarkRitual::activateTrigger(Event e){
	if(e == Event::StartOfTurn){
		if(initCharge >= costCharge){
			owner->setMagic(owner->getMagic()+1);
			initCharge -= costCharge;
		}
	}
}
