/*********************************************************************
** Program Filename: Hand.cpp
** Author: Joshua Wentzel
** Date: 2/4/2018
** Description: Play Go Fish vs. the computer.
** Input: Playing cards to guess for.
** Output: Go Fish gameplay.
*********************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Hand.hpp"

using namespace std;

Hand::Hand(){
	cards = new Card[52];
	n_cards = 0;
}

void Hand::removeCard(int index){
	for(int c = index; c < n_cards-1; c++){
		cards[c] = cards[c+1];
	}
	n_cards--;
}

void Hand::bookRank(int rank){
	for(int i = 0; i < n_cards; i++){
		if(cards[i].getRank() == rank){
			for(int c = i; c < n_cards-1; c++){
				cards[c] = cards[c+1];
			}
			n_cards--;
			i--;
		}
	
	}
}

void Hand::printCards(){
	if(n_cards == 1){
		cout << "You have " << n_cards << " card in your hand of consisting of:" << endl;
	}
	else
	{
		cout << "You have " << n_cards << " cards in your hand of consisting of:" << endl;
	}
	
	for(int i = 0; i < n_cards; i++){
		int r = cards[i].getRank();
		int s = cards[i].getSuit();
		
		std::string suit;
		if(s == 0){
			suit = "Hearts.";
		}
		else if(s == 1){
			suit = "Diamonds.";
		}
		else if(s == 2){
			suit = "Clubs.";
		}
		else{
			suit = "Spades.";
		}
		cout << ranks[r] << " of " << suit << endl;
	}
	
}

int Hand::getNumCards(){return n_cards;}

void Hand::addCard(Card& card){
	cards[n_cards] = card;
	n_cards++;
}

// add one to the index of that card's rank in rank_array
void Hand::scanCards(int* rank_array){
	for(int i = 0; i < 13; i++){
		rank_array[i] = 0;
	}
	for(int i = 0; i < n_cards; i++){
		rank_array[cards[i].getRank()]++;
	}

}

Card* Hand::getCards(){return cards;}

Hand::~Hand(){
	delete [] cards;
}


