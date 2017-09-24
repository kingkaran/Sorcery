#ifndef _GIANT_H_
#define _GIANT_H_
#include "enchantdec.h"
#include "card.h"
#include "minion.h"
#include <iostream>
#include <string>

class GiantStrength: public EnchantDec{
public:
	GiantStrength(Player *owner);
	void getEffect() override;
};

#endif
