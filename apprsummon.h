#ifndef _APPRSUM_H_
#define _APPRSUM_H_
#include "minion.h"

class ApprenticeSummoner: public Minion{
	int abilityCost;
public:
	ApprenticeSummoner(std::shared_ptr<Card> s, Player *owner);
	~ApprenticeSummoner();
	void activateAction(std::shared_ptr<Card> c) override;
	void activateTrigger(Event e) override;
	int getAbCost()override;
};
#endif
