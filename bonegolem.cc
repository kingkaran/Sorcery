#include "bonegolem.h"
#include "player.h"

using namespace std;

BoneGolem::BoneGolem(shared_ptr<Card> s, Player *owner):
Minion("Bone Golem","","Minion",owner,2,1,3,nullptr,nullptr){
	triggeredAb = s;
}

BoneGolem::~BoneGolem(){}

void BoneGolem::activateAction(std::shared_ptr<Card> c) {}

void BoneGolem::activateTrigger(Event e) {
	triggeredAb->activateTrigger(e);
}
