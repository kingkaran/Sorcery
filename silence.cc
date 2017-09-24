#include "silence.h"
#include "minion.h"
#include "player.h"
#include <iostream>
#include <string>


using namespace std;

Silence::Silence(Player *owner):
EnchantDec("Silence", "Enchanted minion cannot use abilities", 
	"Enchantment", 1, owner){}

void Silence::getEffect(){
	hostMinion->setBlockAbility(true);
	owner->killCard(shared_from_this());
}
