#ifndef __BANISH__
#define __BANISH__
#include "spell.h"
#include "card.h"

class Banish: public Spell{
public:
	Banish(Player *owner);
	~Banish();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
