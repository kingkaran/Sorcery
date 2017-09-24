#ifndef _BONEGOLEM_H_
#define _BONEGOLEM_H_
#include "minion.h"

class BoneGolem: public Minion{
public:
	BoneGolem(std::shared_ptr<Card> s, Player *owner);
	~BoneGolem();
	void activateAction(std::shared_ptr<Card> c) override;
	void activateTrigger(Event e) override;
};

#endif
