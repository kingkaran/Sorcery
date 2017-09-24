#ifndef _POTIONSELLERAB_H_
#define _POTIONSELLERAB_H_
#include "triggeredAbility.h"
class Card;

class PotionSellerAbility: public TriggeredAbility{
public:
	PotionSellerAbility(Player *owner);
	~PotionSellerAbility();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
