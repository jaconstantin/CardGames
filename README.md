# CardGames
C++ card games developed with MSVC

Hi guys, this repository is dedicated for developing various card games using Microsoft Visual Studio. I am uploading only the source files for now to save space. My goal is to publish these apps once they are release stage. As of now, there is only one game in the repository generically named CardGame1.cpp.

-----------------------
CardGame1
-----------------------
This is a simplified one on one black jack game versus an AI. The UI is currently console, where each cards is represented by characters depicting their suit and numbers.

Suit: Clover -> C, Heart -> H, Spade -> S, Diamod -> D
Numbers: 01->10, jack->jk, queen->qn, king->king

The main goal is to achieve a total card value as close to 21. If the player's card value exceeds 21, he automatically loses. If the player's value is less than 21, but the AI exceeds 21, the player wins. Else, the player with a value closer to 21 wins.

Each player starts with $1000 each. Per each game, the winner gets to take a $100 from the loser. The game starts by dealing two cards each, and the player is able to see one of the cards of the AI. The player then decides if he wants to draw another card or not. Doing so will also force to AI to do the same. Also note that the deck will only be replenished if it contains less than 6 cards.

The game ends when one of the players lose all his money, or if a user opts to quit.

For developing purposes, the content of the deck is currently visible while the program is running. I am looking into incorporating graphics into this game.



--------------------
Card Game 2
--------------------
This game currently uses the same console UI as card game 1. This game aims to target a Philippine Card game named "Pusoy Dos", which in English is termed as "Poker 2". It is a 4 player game, so I will shoot for creating a simple AI. Similar card combinations  in Poker is involved in this game such as single cards, pair, straight, full house, etc. 

The game is still being developed. I am currently done doing the classes to support the different Hands or card combinations that can be used in this game. The class contains methods for determining the the type of combination, and its corresponding value that will be used to determine the winner of the game. 

The next step is to create a simple UI to start the game engine.

Card Values:
Here, 3 has the lowest value, while 2 is the highest assuming a circular count
Diamond is the highest suit, followed by Heart, spade, and clover respectively

Rules of the Game:
At the start, the deck is shuffled and is distributed completely among four players A,B,C, and D. The player who got the lowest card 3 of clover will go first.

The player can choose to play a 1 card, 2 card, or a 5 card. The other players will then need to play the same number of cards that is in play, provided that it is of a higher value. For example, Player1 played 3of clover, the next player can play any single card higher than this. If player one played a pair, all other players must play a pair. Players can optionally pass if he does not have an available move. The play should continue until there comes a time that all other players (B,C,D) passed (maybe because PlayerA threw a very high card). If that happens, then playerA gets to play any hand that he wants, be it 1 card, 2 card, or a 5 card. The other players will then need to follow again.

The winner of the game is the person who is able to play all his cards first.
