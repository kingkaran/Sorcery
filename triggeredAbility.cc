#include "triggeredAbility.h"
#include "player.h"

TriggeredAbility::TriggeredAbility(std::string name, std::string desc,
 std::string type, int cost, Player *owner):Spell(name, desc, type, cost, owner){}

TriggeredAbility::~TriggeredAbility(){}
