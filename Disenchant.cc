#include "Disenchant.h"
#include "card.h"
#include "player.h"


using namespace std;

Disenchant::Disenchant(Player *owner):
Spell("Disenchant","Destroy the top enchantment on target minion","Spell",1,owner){}

Disenchant::~Disenchant(){}

void Disenchant::activateAction(shared_ptr<Card> c){
	if(owner->getMagic() >= cost || owner->getTest()){
		if(c != nullptr){
			if(c->getEnchants().size() > 0){
				c->popEnchant();
				owner->killCard(shared_from_this());
			}
		}
	}
}

void Disenchant::activateTrigger(Event e){}
