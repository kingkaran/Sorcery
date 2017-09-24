#ifndef _SILENCE_H_
#define _SILENCE_H_
#include "enchantdec.h"
#include <iostream>
#include <string>

class Silence: public EnchantDec{
public:
	Silence(Player *owner);
	void getEffect() override;
};

#endif
