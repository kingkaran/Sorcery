#ifndef _FIREELEMENT_H_
#define _FIREELEMENT_H_
#include "minion.h"

class FireElemental: public Minion{
public:
	FireElemental(std::shared_ptr<Card> s, Player *owner);
	~FireElemental();
	void activateAction(std::shared_ptr<Card> c) override;
	void activateTrigger(Event e) override;
};

#endif
