#include "stdafx.h"
#include "CppUnitTest.h"
#include "card.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_CardGame
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			CardDeck *deck0 = new CardDeck();
			Assert::AreEqual(deck0->getSize(), 52);
			delete deck0;
			
		}

		TEST_METHOD(TestMethod2)
		{
			CardDeck *deck0 = new CardDeck();
			Assert::AreEqual(deck0->getSize(), 50);
			delete deck0;
		}


	};
}