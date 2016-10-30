// CardGame1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "card.h"


int main()
{
	/*
	CardDeck *deck0 = new CardDeck();

	deck0->show();
	deck0->shuffle();
	deck0->show();
	cout << endl << endl << endl; */

	/*
	Card tmp1 = deck0->draw();
	Card tmp2 = deck0->draw();
	Card tmp3 = deck0->draw();
	Card tmp4 = deck0->draw();
	cout << tmp1.getCardString() << "->" << tmp1.getValue() << endl;
	cout << tmp2.getCardString() << "\t" << tmp2.getValue() << endl;
	cout << tmp3.getCardString() << "->" << tmp3.getValue() << endl;
	cout << tmp4.getCardString() << "\t" << tmp4.getValue() << endl;
	*/


	/*
	CardHand player1, player2;
	player1.deal(deck0);
	player2.deal(deck0);

	player1.show();
	cout << player1.getValue() << endl;
	player2.show();
	cout << player2.getValue() << endl;
	deck0->show();

	cout << endl << endl << endl;
	player2.peek();
	player1.hit(deck0);
	player1.show();
	cout << player1.getValue() << endl;

	cout << endl << endl << endl;
	*/

	Game blackjack;
	blackjack.launch();

	cout << "bye bye";
	
	//delete deck0;

    return 0;
}

