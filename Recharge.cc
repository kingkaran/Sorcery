#include "Recharge.h"
#include "card.h"
#include "player.h"

using namespace std;

Recharge::Recharge(Player *owner):
Spell("Recharge","Your ritual gains 3 charges","Spell",1,owner){}

Recharge::~Recharge(){}

void Recharge::activateAction(shared_ptr<Card> c){
	if(owner->getMagic() >= cost || owner->getTest()){
		if(owner->getRitual() != nullptr){
			if(owner->getMagic() < cost){
				owner->setMagic(0);
			}else{
				owner->setMagic(owner->getMagic() - cost);
			}
			c->setRitualCharge(c->getRitualCharge() + 3);
			owner->killCard(shared_from_this());
		}
	}
}

void Recharge::activateTrigger(Event e){}
