#ifndef _APPRSUMMONAB_H_
#define _APPRSUMMONAB_H_
#include "activatedAbility.h"
class Card;

class ApprenticeSummonerAbility: public ActivatedAbility{
public:
	ApprenticeSummonerAbility(Player *owner);
	~ApprenticeSummonerAbility();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
