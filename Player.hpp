#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Hand.hpp"

class Player {
	private:
		Hand hand;
		int* books;  // Array with ranks for which the player has books.
		int n_books;
	public:
		// must have constructors, destructor, accessor methods, and mutator methods
		Player();
		
		Hand* getHand();
		int askForChoice();
		int randPickCard();
		void printBooks();
		int getNumBooks();
		void checkForBooks(bool);
		~Player();
		//void freeMemory();
};

#endif