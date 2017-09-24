#ifndef _NOVICE_H_
#define _NOVICE_H_
#include "minion.h"
class NovicePyromancer: public Minion{
	int abilityCost;
public:
	NovicePyromancer(std::shared_ptr<Card> s,Player *owner);
	~NovicePyromancer();
	void activateAction(std::shared_ptr<Card> c) override;
	void activateTrigger(Event e) override;
	int getAbCost()override;
};

#endif
