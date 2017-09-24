#include "potionseller.h"
using namespace std;

PotionSeller::PotionSeller(shared_ptr<Card> s, Player *owner):
Minion("Potion Seller","","Minion",owner,2,1,3,nullptr,nullptr){
	triggeredAb = s;
}

PotionSeller::~PotionSeller(){}

void PotionSeller::activateAction(std::shared_ptr<Card> c) {}

void PotionSeller::activateTrigger(Event e) {
	triggeredAb->activateTrigger(e);
}

