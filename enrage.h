#ifndef _ENRAGE_H_
#define _ENRAGE_H_
#include "enchantdec.h"
#include "card.h"
#include "minion.h"
#include <iostream>
#include <string>

class Enrage: public EnchantDec{
public:
	Enrage(Player *owner);
	void getEffect() override;	
};

#endif
