#ifndef _MASTERSUMMONAB_H_
#define _MASTERSUMMONAB_H_
#include "activatedAbility.h"
class Card;

class MasterSummonerAbility: public ActivatedAbility{
public:
	MasterSummonerAbility(Player *owner);
	~MasterSummonerAbility();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
