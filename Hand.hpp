#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"

class Hand {
	private:
		Card* cards;
		int n_cards;  // Number of cards in the hand.
	public:
		// must have constructors, destructor, accessor methods, and mutator methods
	Hand();
	int getNumCards();
	void scanCards(int*); 
	void addCard(Card&);
	void printCards();
	void bookRank(int);
	void removeCard(int);
	Card* getCards();
	//void freeMemory();
	~Hand();
};
#endif