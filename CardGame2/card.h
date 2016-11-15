#pragma once
//------------------
//--header file for defining the card class
//--same Card and CardDeck definition from CardGame1
//-----------------

#include "stdafx.h"

using namespace std;

enum cardSuit_t { clover, spade, heart, diamond };
enum cardNum_t { ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king };

enum fiveCardType_t { invalid, straight, flushes, fullHouse, quadro, straightFlush };

class Card {
	cardSuit_t suit;
	cardNum_t num;

	static const int valueArray[13];
	static const int valueNumArray[13];
	static const int valueSuitArray[4];
	static const string suitArray[4];
	static const string numArray[13];

public:
	Card(cardSuit_t inSuit = clover, cardNum_t inNum = three) :suit(inSuit), num(inNum) {}  //constructor using suit and num
	string getCardString();
	int getValue();          //for blackjack game
	int getNumValue() const;       //for poker 2 game
	int getSuitValue() const;      
	const bool operator<(const Card &o) const;
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




//--------------------------------------
//start defining classes for CardGame 2
//--------------------------------------

//abstract base class for a card set that is used to play
class PlayHand {
public:
	virtual int getValue() = 0;
	virtual bool isAllowed() = 0;
	virtual string getHandString() = 0;
};

//-------------------------------
//subclass for one card playhand
//------------------------------
class OneCard: public PlayHand {
	Card card;
public:
	OneCard(Card inCard):card(inCard){}
	void setCard(Card inCard);

	virtual int getValue();
	virtual bool isAllowed();
	virtual string getHandString();
};

//-------------------------
//subclass for a pair
//-------------------------
class PairCard : public PlayHand {
	Card card[2];
public:
	PairCard(Card inCard[2]);
	void setCard(Card inCard[2]);

	virtual int getValue();
	virtual bool isAllowed();
	virtual string getHandString();
};

//------------------------------
//subclass for a five card
//use template for iterators
//------------------------------
class FiveCard : public PlayHand {
	array<Card, 5> card;
	fiveCardType_t type;

	//various functions to check different combinations of five cards
	bool isStraight();
	bool isFlush();
	bool isFullHouse();
	bool isQuadro();
	bool isStraightFlush();
	void setType();

public:
	FiveCard(Card inCard[5]);
	void setCard(Card inCard[5]);

	void sort();
	string getStringType();

	virtual int getValue();
	virtual bool isAllowed();
	virtual string getHandString();
};

