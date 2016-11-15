// CardGame2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "card.h"


int main()
{
	
	CardDeck *deck0 = new CardDeck();

	deck0->show();
	deck0->shuffle();
	deck0->show();
	cout << endl << endl << endl; 

	OneCard a(deck0->draw());
	cout << a.getHandString() << "   " << a.getValue() << endl << endl;

	//manual test for getting the value of a single card
	for (int i = 0; i < 13; ++i) {
		a.setCard(Card(clover,static_cast<cardNum_t>(i)));
		cout << a.getHandString() << "   " << a.getValue() << "  " << a.isAllowed() << endl << endl;
	}

	for (int i = 0; i < 4; ++i) {
		a.setCard(Card(static_cast<cardSuit_t>(i), three));
		cout << a.getHandString() << "   " << a.getValue() << endl << endl;
	}

	//manual test for pairCards, allowed and getValue
	Card b[2] = { Card(clover,three),Card(heart,three) };
	PairCard pc1(b);
	cout << pc1.getHandString() << "  " << pc1.getValue() << "  " << pc1.isAllowed() << endl << endl;

	b[0] = Card(diamond, four);
	b[1] = Card(spade, four);
	pc1.setCard(b);
	cout << pc1.getHandString() << "  " << pc1.getValue() << "  " << pc1.isAllowed() << endl << endl;

	b[0] = Card(clover, four);
	b[1] = Card(spade, five);
	pc1.setCard(b);
	cout << pc1.getHandString() << "  " << pc1.getValue() << "  " << pc1.isAllowed() << endl << endl;

	//manual test for FiveCards, constructor and sort
	Card c[5] = { Card(clover,three), Card(heart,four), Card(spade,five), Card(diamond,six), Card(clover,ace) };
	FiveCard fc1(c);
	cout << fc1.getHandString() << "   ";
	cout << fc1.getHandString() << endl << endl;

	for (int i = 0; i < 5; ++i) {
		c[i] = deck0->draw();
	}

	fc1.setCard(c);
	cout << fc1.getHandString() << "   ";
	fc1.sort();
	cout << fc1.getHandString() << endl << endl;

	//manual test for allowed straight/flush/full house
	//need to make is##### functions public if you want to remove the comment parts
	c[0] = Card(clover,ace);
	c[1] = Card(clover,two);
	c[2] = Card(heart,three);
	c[3] = Card(spade,four);
	c[4] = Card(diamond,five);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  "  << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;

	c[0] = Card(clover, ace);
	c[1] = Card(clover, two);
	c[2] = Card(heart, jack);
	c[3] = Card(spade, queen);
	c[4] = Card(diamond, king);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;


	c[0] = Card(clover, three);
	c[1] = Card(clover, four);
	c[2] = Card(heart, six);
	c[3] = Card(spade, seven);
	c[4] = Card(diamond, five);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;


	c[0] = Card(clover, three);
	c[1] = Card(clover, four);
	c[2] = Card(heart, three);
	c[3] = Card(spade, six);
	c[4] = Card(diamond, five);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;


	c[0] = Card(clover, three);
	c[1] = Card(clover, four);
	c[2] = Card(clover, six);
	c[3] = Card(clover, seven);
	c[4] = Card(clover, five);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;


	c[0] = Card(spade, jack);
	c[1] = Card(spade, queen);
	c[2] = Card(spade, two);
	c[3] = Card(spade, ten);
	c[4] = Card(spade, eight);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;

	c[0] = Card(heart, three);
	c[1] = Card(heart, four);
	c[2] = Card(heart, three);
	c[3] = Card(heart, six);
	c[4] = Card(heart, five);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;


	c[0] = Card(spade, three);
	c[1] = Card(heart, eight);
	c[2] = Card(spade, eight);
	c[3] = Card(clover, three);
	c[4] = Card(diamond, eight);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;


	c[0] = Card(spade, two);
	c[1] = Card(heart, eight);
	c[2] = Card(spade, eight);
	c[3] = Card(clover, two);
	c[4] = Card(diamond, two);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;


	c[0] = Card(spade, two);
	c[1] = Card(heart, king);
	c[2] = Card(spade, eight);
	c[3] = Card(clover, two);
	c[4] = Card(diamond, two);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;


	c[0] = Card(spade, eight);
	c[1] = Card(heart, eight);
	c[2] = Card(diamond, eight);
	c[3] = Card(clover, eight);
	c[4] = Card(diamond, two);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;


	c[0] = Card(spade, ace);
	c[1] = Card(heart, ace);
	c[2] = Card(spade, eight);
	c[3] = Card(clover, ace);
	c[4] = Card(diamond, ace);
	fc1.setCard(c);
	//cout << fc1.getHandString() << "  " << fc1.isStraight() << "  " << fc1.isFlush() << "  " << fc1.isFullHouse() << "  " << fc1.isQuadro() << endl << endl;
	cout << fc1.getHandString() << "  " << fc1.getStringType() << "  " << fc1.isAllowed() << "  " << fc1.getValue() << endl;

	delete deck0;

    return 0;
}

