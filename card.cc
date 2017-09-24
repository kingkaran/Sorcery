#include "card.h"
#include "player.h"
#include <iostream>
using namespace std;

Card::Card(string name, string desc, string type, int cost, Player* owner):
name{name},description{desc},cost{cost},type{type},owner{owner}{}

Card::~Card(){}

string Card::getName()const{
	return name;
}

string Card::getDesc()const{
	return description;
}

int Card::getCost()const{
	return cost;
}

string Card::getType()const{
	return type;
}

void Card::setDesc(string desc){
	description = desc;
}

Player *Card::getOwner()const{
	return owner;
}

void Card::setCost(int i){
	cost = i;
}
