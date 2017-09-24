#include "deck.h"
#include "card.h"
#include "player.h"
#include "airelement.h"
#include "earthelement.h"
#include "fireelement.h"
#include "potionseller.h"
#include "apprsummon.h"
#include "novicepyromancer.h"
#include "mastersummon.h"
#include "bonegolem.h"
#include "Banish.h"
#include "Unsummon.h"
#include "Recharge.h"
#include "Disenchant.h"
#include "RaiseDead.h"
#include "Blizzard.h"
#include "giantstrength.h"
#include "enrage.h"
#include "haste.h"
#include "magicfatigue.h"
#include "silence.h"
#include "darkritual.h"
#include "auraofpower.h"
#include "standstill.h"
#include "spell.h"
#include "ritual.h"
#include "activatedAbility.h"
#include "triggeredAbility.h"
#include "BoneGolemAbility.h"
#include "FireElementalAbility.h"
#include "ApprenticeSummonerAbility.h"
#include "PotionSellerAbility.h"
#include "MasterSummonerAbility.h"
#include "NovicePyromancerAbility.h"
#include <iostream>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

Deck::Deck(bool test){
	owner = nullptr;
	cardNum = 0;
	testMode = test;
}

Deck::~Deck(){}

vector<shared_ptr<Card>> & Deck::getCards(){
	return cards;
}

void Deck::setOwner(Player *p){
	owner = p;
	//initDeck();
}

void Deck::randomize(int seed){
	srand(seed);
	for(int i = 0; i < cards.size(); ++i){
		int r = rand() % cards.size();
		shared_ptr<Card> temp = cards[i];
		cards[i] = cards[r];
		cards[r] = temp;
	}
}

void Deck::initDeck(string name, int seed){
	string s;
	string pass;
	string maybe;
	ifstream f(name);
	while(getline(f,s)){
		istringstream ss{s};
		while(ss >> maybe){
			pass += maybe + " ";
		}
		addCard(pass);
		pass = "";
		s = "";
	}
	if(testMode == false)
		randomize(seed);
	f.close();
}


void Deck::addCard(string s){
	if(s == "Air Elemental "){
		cards.emplace(cards.begin(),make_shared<AirElemental>(owner));
	}else if(s == "Earth Elemental "){
		cards.emplace(cards.begin(),make_shared<EarthElemental>(owner));
	}else if(s == "Bone Golem "){
		cards.emplace(cards.begin(),make_shared<BoneGolem>(make_shared<BoneGolemAbility>(owner),owner));
	}else if(s == "Fire Elemental "){
		cards.emplace(cards.begin(),make_shared<FireElemental>(make_shared<FireElementalAbility>(owner),owner));
	}else if(s == "Potion Seller "){
		cards.emplace(cards.begin(),make_shared<PotionSeller>(make_shared<PotionSellerAbility>(owner),owner));
	}else if(s == "Novice Pyromancer "){
		cards.emplace(cards.begin(),make_shared<NovicePyromancer>(make_shared<NovicePyromancerAbility>(owner),owner));
	}else if(s == "Apprentice Summoner "){
		cards.emplace(cards.begin(),make_shared<ApprenticeSummoner>(make_shared<ApprenticeSummonerAbility>(owner),owner));
	}else if(s == "Master Summoner "){
		cards.emplace(cards.begin(),make_shared<MasterSummoner>(make_shared<MasterSummonerAbility>(owner),owner));
	}else if(s == "Banish "){
		cards.emplace(cards.begin(),make_shared<Banish>(owner));
	}else if(s == "Unsummon "){
		cards.emplace(cards.begin(),make_shared<Unsummon>(owner));
	}else if(s == "Recharge "){
		cards.emplace(cards.begin(),make_shared<Recharge>(owner));
	}else if(s == "Disenchant "){
		cards.emplace(cards.begin(),make_shared<Disenchant>(owner));
	}else if(s == "Raise Dead "){
		cards.emplace(cards.begin(),make_shared<RaiseDead>(owner));
	}else if(s == "Blizzard "){
		cards.emplace(cards.begin(),make_shared<Blizzard>(owner));
	}else if(s == "Giant Strength "){
		cards.emplace(cards.begin(),make_shared<GiantStrength>(owner));
	}else if(s == "Enrage "){
		cards.emplace(cards.begin(),make_shared<Enrage>(owner));
	}else if(s == "Haste "){
		cards.emplace(cards.begin(),make_shared<Haste>(owner));
	}else if(s == "Magic Fatigue "){
		cards.emplace(cards.begin(),make_shared<MagicFatigue>(owner));
	}else if(s == "Silence "){
		cards.emplace(cards.begin(),make_shared<Silence>(owner));
	}else if(s == "Dark Ritual "){
		cards.emplace(cards.begin(),make_shared<DarkRitual>(owner));
	}else if(s == "Aura of Power "){
		cards.emplace(cards.begin(),make_shared<AuraOfPower>(owner));
	}else if(s == "Standstill "){
		cards.emplace(cards.begin(),make_shared<Standstill>(owner));
	}
}

shared_ptr<Card> Deck::topCard(){
	if(cards.size() > 0){
		auto retThis = cards.back();
		cards.pop_back();
		return retThis;
	}
	return nullptr;
}
