#ifndef DECK_HPP
#define DECK_HPP

#include "Player.hpp"
#include "Card.hpp"

class Deck {
	private:
		Card cards[52];
		int n_cards;  // Number of cards remaining in the deck.
	public:
		// must have constructors, destructor, accessor methods, and mutator methods
		Deck();
		void shuffle();
		void deal(Player*, int);
		bool fishFor(Player*, int, bool);
};

#endif