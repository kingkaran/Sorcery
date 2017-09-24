#include "enrage.h"
#include <iostream>
#include <string>

using namespace std;

Enrage::Enrage(Player *owner):
EnchantDec("Enrage", "", "Enchantment", 2, owner){}

void Enrage::getEffect(){
	hostMinion->setAttack(hostMinion->getAttack()*2);
	hostMinion->setDefence(hostMinion->getDefence()*2);
	
}
