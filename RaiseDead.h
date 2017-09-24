#ifndef __RAISEDEAD_H_
#define __RAISEDEAD_H_
#include "spell.h"
#include "card.h"

class RaiseDead: public Spell{
public:
	RaiseDead(Player *owner);
	~RaiseDead();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
