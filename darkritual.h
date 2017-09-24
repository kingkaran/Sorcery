#ifndef _DARKRITUAL_H_
#define _DARKRITUAL_H_
#include "ritual.h"

class DarkRitual: public Ritual{
public:
	DarkRitual(Player *owner);
	~DarkRitual();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
