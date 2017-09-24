#include "magicfatigue.h"
#include "player.h"
#include <iostream>
#include <string>

using namespace std;

MagicFatigue::MagicFatigue(Player *owner):
EnchantDec("Magic Fatigue", "Enchanted minion's activated ability costs 2 more", 
	"Enchantment", 0, owner){}

void MagicFatigue::getEffect(){
	if(hostMinion->getActivatedAb() != nullptr){
		hostMinion->getActivatedAb()->setCost(hostMinion->getActivatedAb()->getCost() + 2);
		owner->killCard(shared_from_this());
	}
}

