#ifndef _HASTE_H_
#define _HASTE_H_
#include "card.h"
#include "minion.h"
#include "enchantdec.h"
#include <iostream>
#include <string>

class Haste: public EnchantDec{
public:
	Haste(Player *owner);
	void getEffect() override;
};

#endif
