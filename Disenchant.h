#ifndef __DISENCHANT_H_
#define __DISENCHANT_H_
#include "spell.h"
#include "card.h"

class Disenchant: public Spell{
public:
	Disenchant(Player *owner);
	~Disenchant();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
