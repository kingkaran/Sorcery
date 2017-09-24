#include "ApprenticeSummonerAbility.h"
#include "event.h"
#include "player.h"
#include "prompt.h"
#include <memory>
#include "airelement.h"
using namespace std;

ApprenticeSummonerAbility::ApprenticeSummonerAbility(Player *owner):
ActivatedAbility("Apprentice Summoner Ability", "Summon a 1/1 air elemental",
	"Activated Ability",1,owner){}

ApprenticeSummonerAbility::~ApprenticeSummonerAbility(){}

void ApprenticeSummonerAbility::activateAction(shared_ptr<Card> c){
	int minionCount = owner->getActiveMinions().size();
	int emptySpace = 5 - minionCount;
	int magicCount = owner->getMagic();
	if((emptySpace > 0 && cost <= magicCount) || owner->getTest()){
		if(cost > magicCount){
			owner->setMagic(0);
		}else{
			int set = magicCount - cost;
			owner->setMagic(set);
		}
		owner->addMinion(make_shared<AirElemental>(owner),false);
	}else{
		Prompt p;
		p.magicError();
	}
}

void ApprenticeSummonerAbility::activateTrigger(Event e){}

