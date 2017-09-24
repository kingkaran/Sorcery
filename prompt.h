#ifndef _PROMPT_H_
#define _PROMPT_H_
#include <memory>
class Board;
class Player;
class Card;

class Prompt{
public:
	void helpMessage();
	void testHelp();
	void displayPrompt(int i);
	void displayBoard(Board *b);
	void displayHand(Player *p);
	void inspectMinion(Card *m);
	void winMessage(Player *p);
	void magicError();
	void noAct();
	void switchMsg(Player *p1, Player *p2);
	void handEmpty();
};

#endif
