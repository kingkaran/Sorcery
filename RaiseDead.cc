#include "RaiseDead.h"
#include "card.h"
#include "player.h"

using namespace std;

RaiseDead::RaiseDead(Player *owner):
Spell("Raise Dead",
	"Resurrect the top minion in your graveyard and set its defence to 1",
	"Spell",1,owner){}

RaiseDead::~RaiseDead(){}

void RaiseDead::activateAction(shared_ptr<Card> c){
	if(owner->getMagic() >= cost || owner->getTest()){
		if(c != nullptr){
			c->setDefence(1);
			bool revved = c->getOwner()->revive(c);
			if(revved){
				owner->killCard(shared_from_this());
			}
		}
	}
}

void RaiseDead::activateTrigger(Event e){}
