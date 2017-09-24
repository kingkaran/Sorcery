#ifndef _FIREELEMAB_H_
#define _FIREELEMAB_H_
#include "triggeredAbility.h"
class Card;

class FireElementalAbility: public TriggeredAbility{
public:
	FireElementalAbility(Player *owner);
	~FireElementalAbility();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
