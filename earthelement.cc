#include "earthelement.h"
#include "player.h"

EarthElemental::EarthElemental(Player *owner):
Minion("Earth Elemental","","Minion",owner,3,4,4,nullptr,nullptr){}

EarthElemental::~EarthElemental(){}

void EarthElemental::activateAction(std::shared_ptr<Card> c) {}

void EarthElemental::activateTrigger(Event e) {}
