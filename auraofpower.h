#ifndef _AURAOFPOWER_H_
#define _AURAOFPOWER_H_
#include "ritual.h"

class AuraOfPower: public Ritual{
public:
	AuraOfPower(Player *owner);
	~AuraOfPower();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
