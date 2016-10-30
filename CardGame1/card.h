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
public:
	Card(cardSuit_t inSuit = clover, cardNum_t inNum = three):suit(inSuit),num(inNum){}
	string getCardString();
};



string Card::getCardString() {
	string tmpStr1, tmpStr2;

	switch (suit) {
		case clover:
			tmpStr1 = "C";
			break;
		case spade:
			tmpStr1 = "S";
			break;
		case heart:
			tmpStr1 = "H";
			break;
		default:
			tmpStr1 = "D";
			break;
	}

	switch (num) {
		case ace:
			tmpStr2 = "01";
			break;
		case two:
			tmpStr2 = "02";
			break;
		case three:
			tmpStr2 = "03";
			break;
		case four:
			tmpStr2 = "04";
			break;
		case five:
			tmpStr2 = "05";
			break;
		case six:
			tmpStr2 = "06";
			break;
		case seven:
			tmpStr2 = "07";
			break;
		case eight:
			tmpStr2 = "08";
			break;
		case nine:
			tmpStr2 = "09";
			break;
		case ten:
			tmpStr2 = "10";
			break;
		case jack:
			tmpStr2 = "jk";
			break;
		case queen:
			tmpStr2 = "qn";
			break;
		default:
			tmpStr2 = "kg";
			break;
	}
	
	return tmpStr1 + tmpStr2;
}