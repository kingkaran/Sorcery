#ifndef _TRIGGERED_H_
#define _TRIGGERED_H_
#include "spell.h"

class TriggeredAbility: public Spell{
public:
	TriggeredAbility(std::string name, std::string desc,
         std::string type, int cost, Player *owner);
	~TriggeredAbility();
};

#endif
