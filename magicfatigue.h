#ifndef _MAGIC_H_
#define _MAGIC_H_
#include "enchantdec.h"
#include "card.h"
#include "minion.h"
#include <iostream>
#include <string>

class MagicFatigue: public EnchantDec{
public:
	MagicFatigue(Player *owner);
	void getEffect() override;
};

#endif
