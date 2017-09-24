#ifndef _AIRELEMENT_H_
#define _AIRELEMENT_H_
#include "minion.h"
#include "event.h"

class AirElemental: public Minion{
public:
	AirElemental(Player *owner);
	~AirElemental();
	void activateAction(std::shared_ptr<Card> c);
	void activateTrigger(Event e);
};

#endif
