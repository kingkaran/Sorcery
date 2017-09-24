#ifndef _EARTHELEM_H_
#define _EARTHELEM_H_
#include "minion.h"

class EarthElemental: public Minion{
public:
	EarthElemental(Player *owner);
	~EarthElemental();
	void activateAction(std::shared_ptr<Card> c) override;
	void activateTrigger(Event e) override;
};

#endif
