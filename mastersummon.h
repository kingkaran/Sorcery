#ifndef _MASTERSUM_H_
#define _MASTERSUM_H_
#include "minion.h"
class MasterSummoner: public Minion{
	int abilityCost;
public:
	MasterSummoner(std::shared_ptr<Card> s, Player *owner);
	~MasterSummoner();
	void activateAction(std::shared_ptr<Card> c) override;
	void activateTrigger(Event e) override;
	int getAbCost()override;
};

#endif
