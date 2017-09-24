#include "NovicePyromancerAbility.h"
#include "event.h"
#include "player.h"
#include "prompt.h"
using namespace std;

NovicePyromancerAbility::NovicePyromancerAbility(Player *owner):
ActivatedAbility("Novice Pyromancer Ability", "Deal 1 damage to target minion",
	"Activated Ability",1,owner){}

NovicePyromancerAbility::~NovicePyromancerAbility(){}

void NovicePyromancerAbility::activateAction(shared_ptr<Card> c){
	if(owner->getMagic() >= cost || owner->getTest()){
		if(owner->getMagic() < cost){
			owner->setMagic(0);
		}else{
			owner->setMagic(owner->getMagic() - cost);
		}
		c->beAttacked(1);
	}else{
		Prompt p;
		p.magicError();
	}
}

void NovicePyromancerAbility::activateTrigger(Event e){}

