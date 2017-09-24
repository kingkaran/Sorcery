#include "FireElementalAbility.h"
#include "event.h"
#include "player.h"
#include <memory>
#include "airelement.h"
using namespace std;

FireElementalAbility::FireElementalAbility(Player *owner):
TriggeredAbility("Fire Elemental Ability", "Whenever an opponent's minion enters play, deal 1 damage to it.",
	"Triggered Ability",2,owner){}

FireElementalAbility::~FireElementalAbility(){}

void FireElementalAbility::activateAction(shared_ptr<Card> c){}

void FireElementalAbility::activateTrigger(Event e){}
