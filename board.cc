#include "board.h"
#include "deck.h"
#include "player.h"
#include "prompt.h"
#include "card.h"
using namespace std;

//Constructor takes in 2 player pointers, p1, and p2, and active is default to p1
//boardState is an empty string at the beginning,
Board::Board(){
	p1 = nullptr;
	p2 = nullptr;
	activePlayer = nullptr;
}

Board::~Board(){}


void Board::takeTurn(Player *p){
	p->takeTurn();
}


void Board::setActive(Player *p){
	Prompt pro;
	pro.switchMsg(activePlayer,p);
	activePlayer->endTurn();
	activePlayer = p;
	p->takeTurn();
	//if any other active abilities or triggered abilities are accounted
}

Player *Board::getActive()const{
	return activePlayer;
}

Player *Board::getInactive()const{
	if(activePlayer == p1){
		return p2;
	}
	return p1;
}

void Board::setPlayers(Player *p1, Player *p2){
	this->p1 = p1;
	this->p2 = p2;
	activePlayer = this->p1;
}

void Board::dealDamage(int i){
	p1->dealDamage(i);
	p2->dealDamage(i);
}

Player *Board::getP1()const{
	return p1;
}

Player *Board::getP2()const{
	return p2;
}
