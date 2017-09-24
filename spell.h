#ifndef __SPELL_H_
#define __SPELL_H_
#include <string>
#include "card.h"
#include "event.h"
class Player;

class Spell: public Card{
public:
   Spell(std::string name, std::string desc,
         std::string type, int cost, Player *owner);
   virtual ~Spell();
   int getAttack()const override;
   void attack(std::shared_ptr<Card> c) override;
   void attack(Player *p) override;
   void beAttacked(int i) override;
   void popEnchant()override;
   int getDefence()const override;
   int getActionCharge()const override;
   void setActionCharge(int i) override;
   void inspect() override;
   void setAttack(int i) override;
   void getEffect() override;
   void setDefence(int i) override;
   void addEnchant(std::shared_ptr<Card> c) override;
   //void setHost(std::shared_ptr<Card> c) override;

   void setHost(Card * c)override;
   void setBlockAbility(bool b) override;
   int getRitualCharge() const override;
   void setRitualCharge(int i) override;
   int getRitualCost()override;
   std::shared_ptr<Card> getActivatedAb()override;
   std::shared_ptr<Card> getTriggeredAb()override;
   std::vector<std::shared_ptr<Card>> getEnchants()override;
   bool abBlocked() override;
   int getAbCost()override;

};
#endif
