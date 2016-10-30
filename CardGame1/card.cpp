#include "stdafx.h"
#include "card.h"
#include <cstdlib>
#include <ctime>

//value of cards in this game
const int Card::valueArray[13] = { 11,2,3,4,5,6,7,8,9,10,10,10,10 };

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


//initialize only
CardHand::CardHand() {
	hand[0] = Card();
	hand[1] = Card();
	hand[2] = Card();
	size = 0;
}


void CardHand::deal(CardDeck *deck) {
	hand[0] = deck->draw();
	hand[1] = deck->draw();
	size = 2;
}



void CardHand::show() {
	if(size > 1) cout << "{" << hand[0].getCardString() << "," << hand[1].getCardString();
	if(size > 2) cout << "," << hand[2].getCardString();
	cout << "}\n";
}

void CardHand::hit(CardDeck *deck) {
	hand[2] = deck->draw();
	size = 3;
}

void CardHand::peek() {
	if (size > 1) cout << "{" << hand[0].getCardString() << "}\n";
}

int CardHand::getValue() {
	int tmpX = 0;
	for (int x = 0; x < size; ++x) {
		tmpX += hand[x].getValue();
	}

	int x = 0;
	while ( (tmpX > 21) && (x<3) ) {
		if (hand[x].getValue() == 11) tmpX = tmpX - 11;
		++x;
	}
	
	return tmpX;
}

Game::Game() {
	player1 = CardHand();
	player2 = CardHand();
	deck = new CardDeck();
	money1 = 1000;
	money2 = 1000;

	deck->shuffle();
	cout << "*************************";
	cout << "let the games begin";
	cout << "*************************";
	cout << endl << endl;
}

Game::~Game() {
	delete deck;
}


void Game::deal() {
	int cmd_tmp;

	cout << "debug... showing contents of the deck";
	deck->show(); cout << endl << endl;

	cout << "cards had been drawn!!";
	player1.deal(deck);
	player2.deal(deck);

	cout << "your hand ->"; player1.show();
	cout << "current value ->" << player1.getValue();
	cout << endl << "your opponents' hole card"; player2.peek();

	cout << endl << endl << "<1> draw another card"
	             << endl << "<2> play and see results" << endl;

	cin >> cmd_tmp;
	if (cmd_tmp == 1) {
		player1.hit(deck);
		player2.hit(deck);
		cout << "your hand ->"; player1.show();
		cout << "current value ->" << player1.getValue() << endl;
	}

	cout << endl << endl;
	cout << "your opponent's hand ->"; player2.show();
	cout << "current value ->" << player2.getValue();
	cout << endl << endl;

	if (player1.getValue() > 21) loseDeal();
	else if (player2.getValue() > 21) winDeal();
	else if (player1.getValue() > player2.getValue()) winDeal();
	else if (player1.getValue() == player2.getValue()) tieDeal();
	else loseDeal();

}

void Game::launch() {
	int cmd_tmp = 1;
	while (cmd_tmp) {

		//if card deck is almost out, refill...
		if (deck->getSize() < 6) {
			delete deck;
			deck = new CardDeck();
			deck->shuffle();
			cout << endl << endl << "a new deck had been shuffled" << endl << endl;
		}

		if ((money1 == 0) || (money2 == 0)) {
			cout << endl << endl << "a player has lost all his money....";
		}

		cout << endl << endl;
		cout << "Your money -> $" << money1 << "    " << "Opponent's Money -> $" << money2 << endl;
		cout << "<0> exit program" << endl;
		cout << "<1> deal another game" << endl;
		cin >> cmd_tmp;
		if(cmd_tmp==1) deal();
	}

	cout << endl << endl << "game has ended goodbye!!";
	
}

void Game::winDeal() {
	cout << "Great you win!!";
	money1 += 100;
	money2 -= 100;
}

void Game::loseDeal() {
	cout << "you LOOSE!!";
	money2 += 100;
	money1 -= 100;
}

void Game::tieDeal() {
	cout << "its a tie!!";
}