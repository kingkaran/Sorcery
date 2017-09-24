#include "prompt.h"
#include "board.h"
#include "player.h"
#include "minion.h"
#include "ascii_graphics.h"
#include <iostream>
#include <memory>
using namespace std;

void Prompt::helpMessage(){
	cout << "---------- Start of help messages ----------" << endl;
	cout << "Here are the available commands:" << endl;
	cout << "help -- displays this message." << endl;
	cout << "end -- ends the current player's turn." << endl;
	cout << "quit -- ends the game immediately with no winner." << endl;
	cout << "attack minion other-minion -- ";
	cout << "Orders minion to attack other-minion." << endl;
	cout << "attack minion -- ";
	cout << "Orders minion to attack the opponent's avatar." << endl;
	cout << "play card [target-player target-card] -- ";
	cout << "Play card, optionally targeting target-card owned by ";
	cout << "target-player." << endl;
	cout << "use minion [target-player target-card] --";
	cout << " Use minion's special ability, optionally targeting ";
	cout << "target-card owned by target-player." << endl;
	cout << "inspect minion -- View a minion's card and all enchantments";
	cout << " on that minion." << endl;
	cout << "hand -- Describe all cards in your hand." << endl;
	cout << "board -- Describe all cards on the board." << endl;
	cout << "------------------ END OF ------------------" << endl;
}

void Prompt::winMessage(Player *p){
	cout << "Congratulations : " << p->getName() << endl;
	cout << "You are the winner!" << endl;
	cout << "See you next time!" << endl;
}

void Prompt::magicError(){
	cout << "Not enough magic." << endl;
}

void Prompt::testHelp(){
	cout << "----------- Start of testing mode commands -----------";
	cout << "draw -- draws a card. ONLY AVAILABLE IN -testing MODE." << endl;
}
void Prompt::noAct(){
	cout << "The minion you called use on doesn't have an activated ability." << endl;
}

void Prompt::displayPrompt(int i){
	if(i == 1){
		cout << "------------ Welcome to Sorcery ------------" << endl;
		cout << "Please enter your name." << endl;
		cout << "Player 1: ";
	}else if(i == 0){
		cout << "Enter your command: ";
	}else if(i == 2){
		cout << "Player 2: ";
	}else if(i == 3){
		cout << "Invalid Command, try again." << endl;
	}else if(i == 4){
		cout << "Let the battle begin, may the best hero win!" << endl;
	}
}

void Prompt::inspectMinion(Card *m){
	//cout << "Hi" << endl;
	for(int i = 0; i < display_minion_no_ability("",1,1,1).size(); ++i){
		if(m->getType() == "Minion"){
			cout << "\033[1;33m"; //display minions in yellow
			if(m->getActivatedAb() != nullptr){
				cout << display_minion_activated_ability(m->getName(),m->getCost(),m->getAttack(),m->getDefence(),1,m->getActivatedAb()->getDesc())[i];
			}else if(m->getTriggeredAb() != nullptr){
				//cout << display_minion_triggered_ability(hand[j]->getName(),hand[j]->getCost(),2,2,"HI")[i];
				cout << display_minion_triggered_ability(m->getName(),m->getCost(),m->getAttack(),m->getDefence(),m->getTriggeredAb()->getDesc())[i];
			}else{
				cout << display_minion_no_ability(m->getName(),m->getCost(),m->getAttack(),m->getDefence())[i];
			}
		}
		cout << endl;
	}

	vector <shared_ptr<Card>> enchantments = m->getEnchants();
	int counter = 0;
	int place = 0;
	int multiplier = 5;
	int diff = -1;
	if(enchantments.size() <= multiplier){
		multiplier = enchantments.size();
	}
	for(int x = 0; x < enchantments.size(); ++x){
		if(diff == 0)
			continue;
		for(int i = 0; i < display_minion_no_ability("",1,1,1).size(); i++){
			for(int j = counter; j < multiplier; ++j){
				cout << "\033[0;32m"; //display rituals in blue
				if(enchantments[j]->getName() == "Giant Strength"){
					cout << display_enchantment_attack_defence(enchantments[j]->getName(), enchantments[j]->getCost(), enchantments[j]->getDesc(), "+2", "+2")[i];
				}
				else if(enchantments[j]->getName() == "Enrage"){
					cout << display_enchantment_attack_defence(enchantments[j]->getName(), enchantments[j]->getCost(), enchantments[j]->getDesc(), "*2", "*2")[i];
				}
				else{
					cout << display_enchantment(enchantments[j]->getName(), enchantments[j]->getCost(), enchantments[j]->getDesc())[i];
				}
				if(i == 0){
					place += 1;
				}
			}
			cout << endl;
		}
		counter += place;
		diff = enchantments.size() - multiplier;
		if(diff < 5){
			multiplier += diff;
		}else{
			multiplier += 5;
		}
	}
	cout << "\033[0m";
}

void Prompt::displayHand(Player *p){
	int handCount = p->getHand().size();
	vector<shared_ptr<Card>> hand = p->getHand();
	for(int i = 0; i < display_minion_no_ability("",1,1,1).size(); ++i){//this is just the placeholder
		for(int j = 0; j < handCount; ++j){
			if(hand[j]->getType() == "Minion"){
				cout << "\033[1;33m"; //display minions in yellow
				if(hand[j]->getActivatedAb() != nullptr){
					cout << display_minion_activated_ability(hand[j]->getName(),hand[j]->getCost(),hand[j]->getAttack(),hand[j]->getDefence(),hand[j]->getAbCost(),hand[j]->getActivatedAb()->getDesc())[i];
				}else if(hand[j]->getTriggeredAb() != nullptr){
					cout << display_minion_triggered_ability(hand[j]->getName(),hand[j]->getCost(),hand[j]->getAttack(),hand[j]->getDefence(),hand[j]->getTriggeredAb()->getDesc())[i];
				}else{
					cout << display_minion_no_ability(hand[j]->getName(),hand[j]->getCost(),hand[j]->getAttack(),hand[j]->getDefence())[i];
				}
			}else if(hand[j]->getType() == "Ritual"){
				cout << "\033[0;31m"; //display rituals in red
				cout << display_ritual(hand[j]->getName(),hand[j]->getCost(),hand[j]->getRitualCost(),hand[j]->getDesc(),hand[j]->getRitualCharge())[i];
			}else if(hand[j]->getType() == "Spell"){
				cout << "\033[0;34m"; //display Spells in blue
				cout << display_spell(hand[j]->getName(), hand[j]->getCost(), hand[j]->getDesc())[i];
			}else if(hand[j]->getType() == "Enchantment"){
				cout << "\033[0;32m"; //display enchantments in green
				if(hand[j]->getName() == "Giant Strength"){
					cout << display_enchantment_attack_defence(hand[j]->getName(), hand[j]->getCost(), hand[j]->getDesc(), "+2", "+2")[i];
				}
				else if(hand[j]->getName() == "Enrage"){
					cout << display_enchantment_attack_defence(hand[j]->getName(), hand[j]->getCost(), hand[j]->getDesc(), "*2", "*2")[i];
				}
				else{
					cout << display_enchantment(hand[j]->getName(), hand[j]->getCost(), hand[j]->getDesc())[i];
				}
			}
		}
		cout << "\033[0m" << endl; //normalization to white
	}
}


void Prompt::displayBoard(Board *b){
	int minionCountp1 = b->getP1()->getActiveMinions().size();
	int minionCountp2 = b->getP2()->getActiveMinions().size();
	shared_ptr<Card> ritualp1 = b->getP1()->getRitual();
	shared_ptr<Card> ritualp2 = b->getP2()->getRitual();
	bool graveyardp1 = false;
	bool graveyardp2 = false;
	if(b->getP1()->getGrave().size() > 0){
		graveyardp1 = true;
	}
	if(b->getP2()->getGrave().size() > 0){
		graveyardp2 = true;
	}
	//Top Border Standard
	cout << "\033[0;36m";
	cout << EXTERNAL_BORDER_CHAR_TOP_LEFT;
	for(int i = 0; i < 165; ++i){
		cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
	}
	cout << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;
	//----END_OF----
	//First Row
	for(int i = 0; i < display_minion_no_ability("Hi",1,3,2).size(); ++i){
		//always keep this since its a border
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		cout << "\033[0m";
		if(ritualp1 != nullptr){
			cout << "\033[0;31m"; //display active ritual of player 1 in red
			cout << display_ritual(ritualp1->getName(),ritualp1->getCost(),ritualp1->getRitualCost(),ritualp1->getDesc(),ritualp1->getRitualCharge())[i];
		  	cout << "\033[0m";
		}else{
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		cout << CARD_TEMPLATE_EMPTY[i];
		cout << "\033[0;95m";
		cout << display_player_card(1,b->getP1()->getName(),b->getP1()->getHP(),b->getP1()->getMagic())[i];
		cout << "\033[0m";
		cout << CARD_TEMPLATE_EMPTY[i];
		if(graveyardp1){
			shared_ptr<Card> temp = b->getP1()->getGrave().back();
			cout << "\033[0;31m"; //display graveyard of player 1 in red
			if(temp->getActivatedAb() != nullptr){
				cout << display_minion_activated_ability(temp->getName(),temp->getCost(),temp->getAttack(),temp->getDefence(),temp->getActivatedAb()->getCost(),temp->getActivatedAb()->getDesc())[i];
			}else if(temp->getTriggeredAb() != nullptr){
				cout << display_minion_triggered_ability(temp->getName(),temp->getCost(),temp->getAttack(),temp->getDefence(),temp->getTriggeredAb()->getDesc())[i];
			}else{
				cout << display_minion_no_ability(temp->getName(),temp->getCost(),temp->getAttack(),temp->getDefence())[i];
			}  
			cout << "\033[0m";
		}else{
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		//always keep this since its a border
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN  << endl;
	}
	//----END_OF----
	//Legit Second row
	for(int i = 0; i < display_minion_no_ability("Hi",1,3,2).size(); ++i){
		//always keep this since its a border
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		vector<shared_ptr<Card>> temp1 = b->getP1()->getActiveMinions();
		cout << "\033[1;33m"; //display active minions of player1 in yellow
		for(int j = 0; j < minionCountp1; ++j){
			if(temp1[j]->getActivatedAb() != nullptr){
				cout << display_minion_activated_ability(temp1[j]->getName(),temp1[j]->getCost(),temp1[j]->getAttack(),temp1[j]->getDefence(),temp1[j]->getActivatedAb()->getCost(),temp1[j]->getActivatedAb()->getDesc())[i];
			}else if(temp1[j]->getTriggeredAb() != nullptr){
				cout << display_minion_triggered_ability(temp1[j]->getName(),temp1[j]->getCost(),temp1[j]->getAttack(),temp1[j]->getDefence(),temp1[j]->getTriggeredAb()->getDesc())[i];
			}else{
				cout << display_minion_no_ability(temp1[j]->getName(),temp1[j]->getCost(),temp1[j]->getAttack(),temp1[j]->getDefence())[i];
			}
		}
		cout << "\033[0m";
		for(int x = 0; x < 5 - minionCountp1; ++x){
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN  << endl;
	}
	//----END_OF----
	//Center Graphic
	for(int i = 0; i < CENTRE_GRAPHIC.size(); ++i){
		cout << "\033[0;35m" << CENTRE_GRAPHIC[i] << "\033[0m" << endl;
    }
	//----END_OF----
	//Legit Second row
	for(int i = 0; i < display_minion_no_ability("Hi",1,3,2).size(); ++i){
		//always keep this since its a border
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		vector<shared_ptr<Card>> temp1 = b->getP2()->getActiveMinions();
		cout << "\033[1;33m";//display active minions of player 2 in yellow
		for(int j = 0; j < minionCountp2; ++j){
			if(temp1[j]->getActivatedAb() != nullptr){
				cout << display_minion_activated_ability(temp1[j]->getName(),temp1[j]->getCost(),temp1[j]->getAttack(),temp1[j]->getDefence(),temp1[j]->getActivatedAb()->getCost(),temp1[j]->getActivatedAb()->getDesc())[i];
			}else if(temp1[j]->getTriggeredAb() != nullptr){
				cout << display_minion_triggered_ability(temp1[j]->getName(),temp1[j]->getCost(),temp1[j]->getAttack(),temp1[j]->getDefence(),temp1[j]->getTriggeredAb()->getDesc())[i];
			}else{
				cout << display_minion_no_ability(temp1[j]->getName(),temp1[j]->getCost(),temp1[j]->getAttack(),temp1[j]->getDefence())[i];
			}
		}
		cout << "\033[0m";
		for(int x = 0; x < 5 - minionCountp2; ++x){
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN  << endl;
	}
	//----END_OF----
	//Second Row
	for(int i = 0; i < display_minion_no_ability("Hi",1,3,2).size(); ++i){
		//always keep this since its a border
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN;
		if(ritualp2 != nullptr){
			cout << "\033[0;34m"; //display in blue for player 2's ritual
			cout << display_ritual(ritualp2->getName(),ritualp2->getCost(),ritualp2->getRitualCost(),ritualp2->getDesc(),ritualp2->getRitualCharge())[i];
		        cout << "\033[0m";
		}else{
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		cout << CARD_TEMPLATE_EMPTY[i];
		cout << "\033[0;95m";
		cout << display_player_card(1,b->getP2()->getName(),b->getP2()->getHP(),b->getP2()->getMagic())[i];
		cout << "\033[0m";
		cout << CARD_TEMPLATE_EMPTY[i];
		if(graveyardp2){
			cout << "\033[0;31m"; //display in red for player 2's graveyard
			shared_ptr<Card> temp = b->getP2()->getGrave().back();
			if(temp->getActivatedAb() != nullptr){
				cout << display_minion_activated_ability(temp->getName(),temp->getCost(),temp->getAttack(),temp->getDefence(),temp->getActivatedAb()->getCost(),temp->getActivatedAb()->getDesc())[i];
			}else if(temp->getTriggeredAb() != nullptr){
				cout <<display_minion_triggered_ability(temp->getName(),temp->getCost(),temp->getAttack(),temp->getDefence(),temp->getTriggeredAb()->getDesc())[i];
			}else{
				cout << display_minion_no_ability(temp->getName(),temp->getCost(),temp->getAttack(),temp->getDefence())[i];
			}
			cout << "\033[0m";
		}else{
			cout << CARD_TEMPLATE_EMPTY[i];
		}
		//always keep this since its a border
		cout << "\033[0;36m";
		cout << EXTERNAL_BORDER_CHAR_UP_DOWN  << endl;
	}
	//----END_OF----
	//Bottom Border Standard
	cout << "\033[0;36m";
	cout << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for(int i = 0; i < 165; ++i){
    	cout << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    }
    cout << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << endl;
    cout << "\033[0m";
    //----END_OF----
}

void Prompt::switchMsg(Player *p1, Player *p2){
	string p1Name = p1->getName();
	string p2Name = p2->getName();
	cout << "Switching players from " << p1Name << " to " << p2Name << endl;
	cout << "Active player is now " << p2Name << endl;
}

void Prompt::handEmpty(){
	cout << "Deck is now empty! Good bye!" << endl;
}
