#ifndef __RECHARGE_H_
#define __RECHARGE_H_
#include "spell.h"
#include "card.h"

//The Recharge spell card increase the targeted ritual's charge by 3
class Recharge: public Spell{
public:
	Recharge(Player *owner);
	~Recharge();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};
#endif
