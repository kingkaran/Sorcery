#include "PotionSellerAbility.h"
#include "event.h"
#include "player.h"
#include <memory>
#include "airelement.h"
using namespace std;

PotionSellerAbility::PotionSellerAbility(Player *owner):
TriggeredAbility("Potion Seller Ability", "At the end of your turn, all your minion gain +0/+1.",
	"Triggered Ability",2,owner){}

PotionSellerAbility::~PotionSellerAbility(){}

void PotionSellerAbility::activateAction(shared_ptr<Card> c){
}

void PotionSellerAbility::activateTrigger(Event e){
	if(e == Event::EndOfTurn){
		vector<shared_ptr<Card>> c = owner->getActiveMinions();
		for(int i = 0; i < c.size(); i++){
			c[i]->setDefence(c[i]->getDefence() + 1);
		}
	}
}
