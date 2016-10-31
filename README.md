# CardGames
C++ card games developed with MSVC

Hi guys, this repository is dedicated for developing various card games using Microsoft Visual Studio. I am uploading only the source files for now to save space. My goal is to publish this apps in the Windows store once they are release stage. As of now, there is only one game in the repository generically named CardGame1.cpp.

-----------------------
CardGame1
-----------------------
This is a simplified one on one black jack game versus an AI. The UI is currently console, where each cards is represented by characters depicting their suit and numbers.

Suit: Clover -> C, Heart -> H, Spade -> S, Diamod -> D
Numbers: 01->10, jack->jk, queen->qn, king->king

The main goal is to achieve a total card value as close to 21. If the player's card value exceeds 21, he automatically loses. If the player's value is less than 21, but the AI exceeds 21, the player wins. Else, the player with a value closer to 21 wins.

Each player starts with $1000 each. Per each game, the winner gets to take a $100 from the loser. The game starts by dealing two cards each, and the player is able to see one of the cards of the AI. The player then decides if he wants to draw another card or not. Doing so will also force to AI to do the same. Also note that the deck will only be replenished if it contains less than 6 cards.

The game ends when one of the players lose all his money, or if a user opts to quit.

For developing purposes, the content of the deck is currently visible while the program is running.



