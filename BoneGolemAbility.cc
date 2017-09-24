#include "BoneGolemAbility.h"
#include "event.h"
#include "player.h"
#include <memory>
#include "airelement.h"
using namespace std;

BoneGolemAbility::BoneGolemAbility(Player *owner):
TriggeredAbility("Bone Golem Ability", "Gain +1/+1 whenever a minion leaves play.",
	"Triggered Ability",2,owner){}

BoneGolemAbility::~BoneGolemAbility(){}

void BoneGolemAbility::activateAction(shared_ptr<Card> c){}

void BoneGolemAbility::activateTrigger(Event e){
	if(e == Event::MinionLeaves){
		vector<shared_ptr<Card>> v = owner->getActiveMinions();
		for(int i = 0; i < v.size(); ++i){
			if(v[i]->getName() == "Bone Golem"){
				v[i]->setAttack(v[i]->getAttack() + 1);
				v[i]->setDefence(v[i]->getDefence() + 1);
			}
		}
	}
}
