#ifndef _RITUAL_H_
#define _RITUAL_H_
#include "spell.h"
#include "triggeredAbility.h"

class Ritual: public TriggeredAbility{
protected:
	int initCharge;
	int costCharge;
public:
	Ritual(std::string name, std::string desc,
         std::string type, int cost, Player *owner, int initChrg, int costChrg);
	~Ritual();
	int getRitualCharge() const override;
	void setRitualCharge(int i) override;
	int getRitualCost()override;
};

#endif
