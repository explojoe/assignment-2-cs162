#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Deck.hpp"

class Game {
	private:
		Deck cards;
		Player players[2];
	public:
		// must have constructors, destructor, accessor methods, and mutator methods
		Game();
		Deck getDeck();
		Player* getPlayer(int);
		bool moveCardsFromToOf(bool, int);
		bool checkGameOver();
		~Game();
};
#endif