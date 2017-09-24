#ifndef _NOVICEPYROAB_H_
#define _NOVICEPYROAB_H_
#include "activatedAbility.h"
class Card;

class NovicePyromancerAbility: public ActivatedAbility{
public:
	NovicePyromancerAbility(Player *owner);
	~NovicePyromancerAbility();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
