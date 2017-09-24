#include "haste.h"
#include <iostream>
#include <string>

using namespace std;

Haste::Haste(Player *owner):
EnchantDec("Haste", "Enchanted minion gains +1 action each turn", 
	"Enchantment", 1, owner){}

void Haste::getEffect(){
	hostMinion->setActionCharge(hostMinion->getActionCharge() + 1);
}
