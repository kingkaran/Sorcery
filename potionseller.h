#ifndef _POTIONSELLER_H_
#define _POTIONSELLER_H_
#include "minion.h"
class PotionSeller: public Minion{
public:
	PotionSeller(std::shared_ptr<Card> s,Player *owner);
	~PotionSeller();
	void activateAction(std::shared_ptr<Card> c) override;
	void activateTrigger(Event e) override;
};

#endif
