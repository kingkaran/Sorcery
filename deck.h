#ifndef _DECK_H_
#define _DECK_H_
#include <vector>
#include <memory>
class Card;
class Spell;
class Player;

class Deck{
	std::vector<std::shared_ptr<Card>> cards;
	Player *owner;
	int cardNum;
	bool testMode;
public:
	Deck(bool test);
	~Deck();
	void setOwner(Player *p);
	std::vector<std::shared_ptr<Card>> &getCards();
	void randomize(int seed);
	void addCard(std::string s);
	void initDeck(std::string name, int seed);
	std::shared_ptr<Card>topCard();
};

#endif
