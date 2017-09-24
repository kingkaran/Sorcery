#ifndef _CARD_H_
#define _CARD_H_
#include <string>
#include <memory>
#include <vector>
#include "event.h"
class Player;

class Card: public std::enable_shared_from_this<Card>{
protected:
	std::string name;
	std::string description;
	int cost;
	std::string type;
	Player *owner;
public:
	Card(std::string name, std::string desc, std::string type, int cost, Player* owner);
	virtual ~Card();
	std::string getName()const;
	std::string getDesc()const;
	int getCost()const;
	void setCost(int i);
	void setDesc(std::string desc);
	std::string getType()const;
	Player *getOwner()const;
	virtual int getAttack()const = 0;
	virtual void setAttack(int i) = 0;
	virtual void attack(std::shared_ptr<Card> c) = 0;
	virtual void attack(Player *p) = 0;
	virtual void beAttacked(int i) = 0;
	virtual int getDefence()const = 0;
	virtual int getActionCharge()const = 0;
	virtual void setActionCharge(int i) = 0;
	virtual void inspect() = 0;
	virtual int getRitualCharge()const = 0;
	virtual void setRitualCharge(int i) = 0;
	virtual void popEnchant() = 0;
	virtual void getEffect() = 0;
	virtual void setDefence(int i) = 0;
	virtual void addEnchant(std::shared_ptr<Card> c) = 0;
	virtual void setBlockAbility(bool b) = 0;
	virtual int getRitualCost() = 0;
	virtual void activateAction(std::shared_ptr<Card> c) = 0;
	virtual void activateTrigger(Event e) = 0;
	virtual std::vector<std::shared_ptr<Card>> getEnchants() = 0;
	virtual std::shared_ptr<Card> getActivatedAb() = 0;
	virtual std::shared_ptr<Card> getTriggeredAb() = 0;
	virtual bool abBlocked() = 0;
	virtual int getAbCost() = 0;

	virtual void setHost(Card * c) = 0;
};

#endif

