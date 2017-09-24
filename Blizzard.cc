#include "Blizzard.h"
#include "player.h"


using namespace std;

Blizzard::Blizzard(Player *owner):
Spell("Blizzard","Deal 2 damage to all minions","Spell",3,owner){}

Blizzard::~Blizzard(){}

void Blizzard::activateAction(shared_ptr<Card> c){
	owner->getCurrentBoard()->dealDamage(2);
	owner->killCard(shared_from_this());
}

void Blizzard::activateTrigger(Event e){}

