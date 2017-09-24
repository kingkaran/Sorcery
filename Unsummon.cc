#include "Unsummon.h"
#include "card.h"
#include "player.h"

using namespace std;

Unsummon::Unsummon(Player *owner):
Spell("Unsummon","Return target minion to its owner's hand","Spell",1,owner){}

Unsummon::~Unsummon(){}

void Unsummon::activateAction(shared_ptr<Card> c){
	if(c != nullptr){
		if(owner->getMagic() >= cost || owner->getTest()){
			for(int i = 0; i < c->getEnchants().size(); ++i){
				c->popEnchant();
			}
			c->getOwner()->removeCard(c);
			owner->killCard(shared_from_this());
		}
	}
}

void Unsummon::activateTrigger(Event e){}

