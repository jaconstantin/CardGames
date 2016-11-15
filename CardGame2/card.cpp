#include "stdafx.h"
#include "card.h"
#include <cstdlib>
#include <ctime>

//value of cards in card game 1 of blackjack
const int Card::valueArray[13] = { 11,2,3,4,5,6,7,8,9,10,10,10,10 };

//value of cards in this game: poker 2
const int Card::valueNumArray[13] = { 12,13,1,2,3,4,5,6,7,8,9,10,11 };
const int Card::valueSuitArray[4] = { 1,2,3,4 };

//cards are displayed through a 3-char string representation based on suit and number
const string Card::suitArray[4] = { "C","S","H","D" };
const string Card::numArray[13] = { "01","02","03","04","05","06","07","08","09","10","jk","qn","kg" };


string Card::getCardString() {
	string tmpStr1, tmpStr2;

	tmpStr1 = suitArray[static_cast<int>(suit)];
	tmpStr2 = numArray[static_cast<int>(num)];

	return tmpStr1 + tmpStr2;
}


int Card::getValue() {
	int tmpX = static_cast<int>(num);
	return valueArray[tmpX];
}

int Card::getNumValue() const {
	int tmpX = static_cast<int>(num);
	return valueNumArray[tmpX];
}

int Card::getSuitValue() const {
	int tmpX = static_cast<int>(suit);
	return valueSuitArray[tmpX];
}

const bool Card::operator<(const Card &o) const {
	int tmp1 = 10 * getNumValue() + getSuitValue();
	int tmp2 = 10 * o.getNumValue() + o.getSuitValue();
	return tmp1 < tmp2;
}

//construct 52 distinct cards in a deck
CardDeck::CardDeck() {
	size = 52;
	for (int x = 0; x < 4; ++x) {
		for (int i = 0; i < 13; ++i) {
			//deck[i + (13 * x)] = Card(x,i);
			deck[i + (13 * x)] = Card(static_cast<cardSuit_t>(x), static_cast<cardNum_t>(i));
		}
	}
}

void CardDeck::show() {
	cout << "{";
	for (int x = 0; x < size; ++x) {
		cout << deck[x].getCardString() << ",";
	}
	cout << "}\n";
}

void CardDeck::shuffle() {
	srand(time(0));
	for (int x = 0; x < size; ++x) {
		int r = rand() % size;
		Card temp = deck[x];
		deck[x] = deck[r];
		deck[r] = temp;
	}
}

Card CardDeck::draw() {
	size -= 1;
	return deck[size];
}


//--------------------------------------
//start defining classes for CardGame 2
//--------------------------------------
//value of card depends on both the number and the suit
//#3 is lowest, while #2 is highest through a circular count
//if same number, determine value through the suit
//hence, give numValue x10 value as compared to Suit, and add
int OneCard::getValue() {
	return card.getNumValue() * 10 + card.getSuitValue();
}

void OneCard::setCard(Card inCard) {
	card = inCard;
}

//any one card is an allowed combination
bool OneCard::isAllowed() {
	return true;
}

string OneCard::getHandString() {
	return card.getCardString();
}


//------------------
//Pair Cards
//------------------
PairCard::PairCard(Card inCard[2]) {
	card[0] = inCard[0];
	card[1] = inCard[1];
}

void PairCard::setCard(Card inCard[2]) {
	card[0] = inCard[0];
	card[1] = inCard[1];
}

//return the higher of two single card values
int PairCard::getValue() {
	if(card[0].getSuitValue() > card[1].getSuitValue())
		return card[0].getNumValue() * 10 + card[0].getSuitValue();
	else
		return card[1].getNumValue() * 10 + card[1].getSuitValue();
}

//should be a pair
bool PairCard::isAllowed() {
	return (card[0].getNumValue() == card[1].getNumValue());
}

string PairCard::getHandString() {
	string tmp = card[0].getCardString() + "," + card[1].getCardString();
	return tmp;
}


//------------------
//Five Cards
//------------------

//*****Check the type of five card*****//
bool FiveCard::isStraight() {
	sort();
	for (int i = 0; i < 4; ++i) {
		if (card[i + 1].getNumValue() - card[i].getNumValue() != 1)
			return false;
	}
	return true;
}

bool FiveCard::isFlush() {
	for (int i = 0; i < 4; ++i) {
		if (card[4].getSuitValue() != card[i].getSuitValue())
			return false;
	}
	return true;
}

bool FiveCard::isFullHouse() {
	sort();
	bool tmp1 = ( card[0].getNumValue() == card[1].getNumValue() ) &&  ( card[1].getNumValue() && card[2].getNumValue() ) 
		&& ( card[3].getNumValue() == card[4].getNumValue() );
	bool tmp2 = ( card[0].getNumValue() == card[1].getNumValue() ) && ( card[2].getNumValue() == card[3].getNumValue() ) &&
		( card[3].getNumValue() == card[4].getNumValue() );
	return tmp1 || tmp2;
}

bool FiveCard::isQuadro() {
	sort();
	bool tmp1 = (card[0].getNumValue() == card[1].getNumValue()) && (card[2].getNumValue() == card[3].getNumValue())
		&& (card[1].getNumValue() == card[2].getNumValue());
	bool tmp2 = (card[1].getNumValue() == card[2].getNumValue()) && (card[3].getNumValue() == card[4].getNumValue())
		&& (card[2].getNumValue() == card[3].getNumValue());
	return tmp1 || tmp2;
}

bool FiveCard::isStraightFlush() {
	return isStraight() && isFlush();
}


//set type, must be called whenever the member card changes
void FiveCard::setType() {
	if (isStraightFlush()) type = straightFlush;
	else if (isQuadro()) type = quadro;
	else if (isFullHouse()) type = fullHouse;
	else if (isFlush()) type = flushes;
	else if (isStraight()) type = straight;
	else type = invalid;
}





FiveCard::FiveCard(Card inCard[5]) {
	for (int i = 0; i < 5; ++i) {
		card[i] = inCard[i];
	}
	setType();
}

void FiveCard::setCard(Card inCard[5]) {
	for (int i = 0; i < 5; ++i) {
		card[i] = inCard[i];
	}
	setType();
}

void FiveCard::sort() {
	std::sort(card.begin(), card.end());
}

string FiveCard::getStringType() {
	string tmp;
	
	switch (type) {

	case straight:
		tmp = "straight";
		break;

	case flushes:
		tmp = "flushes";
		break;

	case fullHouse:
		tmp = "fullHouse";
		break;

	case quadro:
		tmp = "quadro";
		break;

	case straightFlush:
		tmp = "straightFlush";
		break;

	default:
		tmp = "invalid";
		break;
	}

	return tmp;
}


//determined by the fiveCard Type, the most improbable has the highest value, represented by values 1000,2000,3000,4000,5000
	//this ensures all five card value is much higher than individual card value whihc is at most 134.
//if same card type, is then determined by the highest single card value contained in the set
int FiveCard::getValue() {
	int tmp = 0;
	//sort();        //for every new entry, we determine the type which automatically sorts the sequence

	switch (type) {

	case straight:   //value = 1000 + value of num card *10 + value of the suit (highest single card)
		tmp = card[4].getNumValue() * 10 + card[4].getSuitValue() + 1000;
		break;

	case flushes:	//value = 2000 + value of the suit weighted by 20 + value of the number (consider suit first, then number of the card, so ensure that each suite increment (1*20) is higher than max range of num  (13) )
		tmp = card[4].getSuitValue() * 20 + card[4].getNumValue() + 2000;
		break;

	case fullHouse: //value = 3000 + num value of the trio  (num value of the trio)  (since this is sorted, element[2] is sure to be part of the trio
		tmp = card[2].getNumValue() + 3000;
		break;

	case quadro: //value = 4000 + num value of the quad
		tmp = card[2].getNumValue() + 4000;
		break;

	case straightFlush: //value=5000+ higehst single card value
		tmp = card[4].getNumValue() * 10 + card[4].getSuitValue() + 5000;
		break;
	}

	return tmp;
}

//do this for a straight
bool FiveCard::isAllowed() {
	if (type == invalid) return false;
	else return true;
}

string FiveCard::getHandString() {
	string tmp;
	for (int i = 0; i < 4; ++i) {
		tmp = tmp + card[i].getCardString() + ",";
	}
	
	return tmp + card[4].getCardString();
}