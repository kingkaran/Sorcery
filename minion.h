#ifndef _MINION_H_
#define _MINION_H_
#include <vector>
#include "card.h"
#include "event.h"
class Player;
class Spell;

class Minion: public Card{
protected:
	int att;
	int def;
	bool abilityBlocked;
	std::shared_ptr<Card> activatedAb;
	std::shared_ptr<Card> triggeredAb;
	int actionCharge;
	std::vector<std::shared_ptr<Card>> enchants;
public:
	Minion(std::string name, std::string desc, std::string type, Player *owner,
		int cost, int atk, int def, std::shared_ptr<Card> active, std::shared_ptr<Card> trigger);
	~Minion() = 0;
	int getAttack()const override;
	void attack(std::shared_ptr<Card> c)override;
	void attack(Player *p)override;
	void beAttacked(int i)override;
	int getDefence()const override;
	void activateAction(std::shared_ptr<Card> c)override;
	void activateTrigger(Event e)override;
	int getActionCharge()const override;
	void setActionCharge(int i)override;
	void inspect() override;
	void addEnchant(std::shared_ptr<Card> c) override;
	//void setHost(std::shared_ptr<Card> c) override;
	void setHost(Card * c) override;
	void popEnchant()override;
	void setAttack(int i)override;
	int getRitualCharge()const override;
	void setRitualCharge(int i)override;
	void getEffect() override;
	void setDefence(int i) override;
	void setBlockAbility(bool b) override;
	int getRitualCost()override;
	std::shared_ptr<Card> getActivatedAb()override;
	std::shared_ptr<Card> getTriggeredAb()override;
	std::vector<std::shared_ptr<Card>> getEnchants()override;
	bool abBlocked() override;
	int getAbCost()override;
};


#endif

