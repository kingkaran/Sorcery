#include "activatedAbility.h"
#include "player.h"

ActivatedAbility::ActivatedAbility(std::string name, std::string desc,
 std::string type, int cost, Player *owner):Spell(name, desc, type, cost, owner){}

ActivatedAbility::~ActivatedAbility(){}
