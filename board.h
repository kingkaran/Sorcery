#ifndef _BOARD_H_
#define _BOARD_H_
#include <iostream>
#include <string>
#include "player.h"

class Board{
	Player *p1;
	Player *p2;
	Player *activePlayer;
public:
	Board();
	~Board();
	Player *getP1()const;
	Player *getP2()const;
	void takeTurn(Player *p);
	void setActive(Player *p);
	Player *getActive()const;
	Player *getInactive()const;
	void setPlayers(Player *p1, Player *p2);
	void dealDamage(int i);
};

#endif
