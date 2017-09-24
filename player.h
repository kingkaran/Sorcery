#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "card.h"
#include "spell.h"
class Deck;
class Card;
class Enchantment;
class Ritual;
class Board;
class Minion;

class Player{
	int hp;
	int magic;
	std::string name;
	std::vector<std::shared_ptr<Card>> hand;
	Deck *deck;
	std::shared_ptr<Card> activeRitual;
	std::vector<std::shared_ptr<Card>> graveyard;
	std::vector<std::shared_ptr<Card>> activeMinions;
	Board *currentBoard;
	int playerNum;
	bool testMode;
public:
	Player(std::string name, Deck *d, Board *b, int num, bool testing);
	~Player();
	bool isDead() const;
	void playCard(int i);
	void play(std::shared_ptr<Card> m);;
	void playCard(int i, int p, int t);
	void play(std::shared_ptr<Card> s, std::shared_ptr<Card> c);
	void play1(std::shared_ptr<Card> e, std::shared_ptr<Card> c);
	int getHP() const;
	int getMagic() const;
	std::vector<std::shared_ptr<Card>>getGrave()const;
	std::vector <std::shared_ptr<Card>>getHand() const;
	void setMagic(int m);
	std::string getName() const;
	void draw();
	void takeTurn();
	void setDeck(Deck *d);
	Deck *getDeck() const;
	std::shared_ptr<Card> getMinion(int i) const;
	std::vector<std::shared_ptr<Card>> getActiveMinions() const;
	std::shared_ptr<Card> getRitual() const;
	void setRitual(std::shared_ptr<Card> c);
	void setHP(int h);
	void addMinion(std::shared_ptr<Card> m, bool fromHand);
	void sendToGrave(std::shared_ptr<Card> c);
	void attack(int i);
	void attack(int i, int j);
	void removeCard(std::shared_ptr<Card> c);
	void use(int i);
	void use(int i, int t, int tc);
	void inspect(int i);
	Board *getCurrentBoard();
	void dealDamage(int i);
	void drawFive();
	bool revive(std::shared_ptr<Card> c);
	void killCard(std::shared_ptr<Card> c);
	void endTurn();
	bool getTest();
};


#endif
