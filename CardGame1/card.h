//------------------
//--header file for defining the card class
//-----------------

#include "stdafx.h"

using namespace std;

enum cardSuit_t{clover, spade, heart, diamond};
enum cardNum_t{ace,two,three,four,five,six,seven,eight,nine,ten,jack,queen,king};

class Card {
	cardSuit_t suit;
	cardNum_t num;

	static const int valueArray[13];
	static const string suitArray[4];
	static const string numArray[13];

public:
	Card(cardSuit_t inSuit = clover, cardNum_t inNum = three):suit(inSuit),num(inNum){}  //constructor using suit and num
	string getCardString();
	int getValue();
};



class CardDeck {
	Card deck[52];
	int size;
public:
	CardDeck();
	void show();
	void shuffle();		 //https://www.uow.edu.au/~lukes/TEXTBOOK/notes-cpp/misc/random-shuffle.html
	Card draw();
	int getSize() { return size; }
};


class CardHand {
	Card hand[3];
	int size;
	int value;
public:
	CardHand();
	void deal(CardDeck*);
	void hit(CardDeck*);
	void show();
	void peek();
	int getValue();
};




class Game {
	CardHand player1;
	CardHand player2;
	int money1;
	int money2;
	CardDeck *deck;

public:
	Game();
	~Game();

	void deal();
	void launch();

	void winDeal();
	void loseDeal();
	void tieDeal();
};
