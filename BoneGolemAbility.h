#ifndef _BONEGOLEMAB_H_
#define _BONEGOLEAB_H_
#include "triggeredAbility.h"
class Card;

class BoneGolemAbility: public TriggeredAbility{
public:
	BoneGolemAbility(Player *owner);
	~BoneGolemAbility();
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
};

#endif
