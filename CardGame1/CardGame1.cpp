// CardGame1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "card.h"


int main()
{
	Card draw1;
	Card draw2(diamond, ten);

	cout << draw1.getCardString() << endl;
	cout << draw2.getCardString() << endl;

    return 0;
}

