#include "giantstrength.h"
#include <iostream>
#include <string>
#include "player.h"

using namespace std;


GiantStrength::GiantStrength(Player *owner):
EnchantDec("Giant Strength", "", "Enchantment", 1, owner){}

void GiantStrength::getEffect(){
	if(hostMinion != nullptr){
		hostMinion->setAttack(hostMinion->getAttack()+2);
		hostMinion->setDefence(hostMinion->getDefence()+2);
	}
}

