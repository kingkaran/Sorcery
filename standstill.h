#ifndef _STANDSTILL_H_
#define _STANDSTILL_H_
#include "ritual.h"

class Standstill: public Ritual{
public:
	Standstill(Player *owner);
	~Standstill();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
