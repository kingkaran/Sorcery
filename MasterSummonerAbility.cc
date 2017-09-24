#include "MasterSummonerAbility.h"
#include "event.h"
#include "player.h"
#include <memory>
#include "airelement.h"
#include "prompt.h"
using namespace std;

MasterSummonerAbility::MasterSummonerAbility(Player *owner):
ActivatedAbility("Master Summoner Ability", "Summon up to three 1/1 air elementals",
	"Activated Ability",2,owner){}

MasterSummonerAbility::~MasterSummonerAbility(){}

void MasterSummonerAbility::activateAction(shared_ptr<Card> c){
	int minionCount = owner->getActiveMinions().size();
	int emptySpace = 5 - minionCount;
	int magicCount = owner->getMagic();
	if ((emptySpace > 0 && cost <= magicCount) || owner->getTest()){
		if(magicCount < cost){
			owner->setMagic(0);
		}else{
			int set = magicCount - cost;
			owner->setMagic(set);
		}
		if(emptySpace > 3){
			emptySpace = 3;
		}
		for(int i = 1; i <= emptySpace;++i){
			owner->addMinion(make_shared<AirElemental>(owner),false);
		}
	}else{
		Prompt p;
		p.magicError();
	}
}

void MasterSummonerAbility::activateTrigger(Event e){}

