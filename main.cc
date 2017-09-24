#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "player.h"
#include "board.h"
#include "event.h"
#include "card.h"
#include "deck.h"
#include "prompt.h"
#include <cstdlib>
#include <ctime>
using namespace std;


int main(int argc, char *argv[]){
	Prompt p;
	bool quitGame = false;
	string choice;
	string p1Name;
	string p2Name;
	string argument;
	string file;
	string deck1 ="default.deck";
	string deck2 = "default.deck";
	vector<string> command;
	bool init = false;
	bool test = false;
	if(argc > 1){
		for(int i=1; i<argc; i++){
			argument = argv[i];
			if(argument == "-deck1"){
				deck1 = argv[i+1];
			}
			else if(argument == "-deck2"){
				deck2 = argv[i+1];
			}
			else if(argument == "-init"){
				init = true;
				file = argv[i+1];
			}
			else if(argument == "-testing"){
				test = true;
			}
		}
	}

	ifstream f;
	p.displayPrompt(1);
	if(init){
		f.open(file, ifstream::in);
		string s;
		getline(f, s);
		istringstream ss(s);
		string placehold;
		while(ss >> placehold){
			p1Name+=placehold + " ";
		}
		p1Name.pop_back();
		cout << endl;
	}
	else{
		getline(cin,p1Name);
	}
	p.displayPrompt(2);
	if(init){
		string s;
		getline(f, s);
		istringstream ss(s);
		string placehold;
		while(ss >> placehold){
			p2Name+=placehold + " ";
		}
		p2Name.pop_back();
		cout << endl;
	}
	else{
		getline(cin,p2Name);
	}

	Board b;
	Deck d{test};
	Deck d1{test};
	srand(time(0));
	Player p1{p1Name, &d, &b, 1,test};
	d.setOwner(&p1);
	d.initDeck(deck1,rand());
	Player p2{p2Name, &d1, &b, 2,test};
	d1.setOwner(&p2);
	d1.initDeck(deck2,rand());
	b.setPlayers(&p1,&p2);
	p1.drawFive();
	p2.drawFive();
	p.displayPrompt(4);
	p.helpMessage();
	p1.takeTurn();
	string placehold;

	while(true){
		if(p1.isDead()){
			p.winMessage(&p2);
			break;
		}else if(p2.isDead()){
			p.winMessage(&p1);
			break;
		}
		if(p1.getDeck()->getCards().size() == 0 || p2.getDeck()->getCards().size() == 0){
			p.handEmpty();
			break;
		}
		p.displayPrompt(0);
		if(init && !f.eof()){
			getline(f, placehold);
			cout << endl;
		}
		else{
			getline(cin,placehold);
		}

		istringstream ss{placehold};
		ss >> choice;
		if(choice == "help"){
			p.helpMessage();
		}else if(choice == "end"){
			b.setActive(b.getInactive());
		}else if(choice == "attack"){
			int target;
			int host;
			if(ss >> host){
				if(ss >> target){
					b.getActive()->attack(host,target);
				}else{
					ss.clear();
					b.getActive()->attack(host);
				}
			}
		}else if(choice == "quit"){
			cout << "See ya next time!" << endl;
			break;
		}else if(choice == "play"){
			char target;
			int playerNum;
			int host;
			if(ss >> host){
				if(ss >> playerNum){
					if(ss >> target){
						int passIn;
						if(target == 'r'){
							passIn = 6;
						}else if(target == '1'){
							passIn = 1;
						}else if(target == '2'){
							passIn = 2;
						}else if(target == '3'){
							passIn = 3;
						}else if(target == '4'){
							passIn = 4;
						}else if(target == '5'){
							passIn = 5;
						}
						b.getActive()->playCard(host,playerNum,passIn);
					}
				}else{
					ss.clear();
					b.getActive()->playCard(host);
				}
			}
		}else if(choice == "use"){
			int host;
			int playerNum;
			int targ;
			if(ss >> host){
				if(ss >> playerNum){
					if(ss >> targ){
						int passIn;
						if(targ == 'r'){
							passIn = 6;
						}else if(targ == '1'){
							passIn = 1;
						}else if(targ == '2'){
							passIn = 2;
						}else if(targ == '3'){
							passIn = 3;
						}else if(targ == '4'){
							passIn = 4;
						}else if(targ == '5'){
							passIn = 5;
						}
						b.getActive()->use(host,playerNum,targ);
					}
				}else{
					ss.clear();
					b.getActive()->use(host);
				}
			}
		}else if(choice == "inspect"){
			int target;
			if(ss >> target){
				b.getActive()->inspect(target);
			}
		}else if(choice == "hand"){
			p.displayHand(b.getActive());
		}else if(choice == "board"){
			p.displayBoard(&b);
		}else if(choice == "discard" && test){
			int host;
			if(ss >> host){
				shared_ptr<Card> card = (b.getActive()->getHand())[host-1];
				b.getActive()->killCard(card);
			}
		}else if(choice == "draw" && test){
			int size = (b.getActive()->getHand()).size();
			if(size < 5){
				b.getActive()->draw();
			}
			else{
				cout << "Sorry, you cannot draw a card!" << endl;
			}
		}else{
			p.displayPrompt(3);
		}
		placehold = "";
	}
}
