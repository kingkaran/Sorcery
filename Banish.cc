#include "Banish.h"
#include "player.h"
#include "prompt.h"

using namespace std;

Banish::Banish(Player *owner):
Spell("Banish","Destroy target minion or ritual","Spell",2,owner){}

Banish::~Banish(){}

void Banish::activateAction(shared_ptr<Card> c){
	if(c != nullptr){
		if(owner->getMagic() >= cost || owner->getTest()){
			c->getOwner()->sendToGrave(c);
			owner->killCard(shared_from_this());
		}
	}
}

void Banish::activateTrigger(Event e){}
