#ifndef __ACTIVATEDABILITY__
#define __ACTIVATEDABILITY__
#include "spell.h"

class ActivatedAbility: public Spell{
public:
	ActivatedAbility(std::string name, std::string desc,
         std::string type, int cost, Player *owner);
	~ActivatedAbility();
};

#endif
