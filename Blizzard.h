#ifndef _BLIZZARD_H_
#define _BLIZZARD_H_
#include "spell.h"
#include "event.h"
#include "board.h"

class Blizzard: public Spell{
public:
	Blizzard(Player *owner);
	~Blizzard();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};


#endif
