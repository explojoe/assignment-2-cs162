/*********************************************************************
** Program Filename: econdata.cpp
** Author: Joshua Wentzel
** Date: 1/22/2018
** Description: Explore state and county economic data.
** Input: Path to file containing state and county economic data.
** Output: Statistics on state and county economic data.
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
Deck::Deck(){
	n_cards = 52;
	for(int s = 0; s < 4; s++){
		for(int r = 0; r < 13; r++){
			cards[s*13+r].initialize(r,s);
			//cout << r << " " << s << endl;
		}
	}
}

bool Deck::fishFor(Player* player, int rank, bool isPlayer){
	if(n_cards > 0){
		Hand* p_hand = player->getHand();	// this may be wrong
		
		p_hand->addCard(cards[n_cards-1]);
		n_cards--;
		
		int r = cards[n_cards+1].getRank();
		int s = cards[n_cards+1].getSuit();
		
		string suit;
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
		
		if(isPlayer){
			cout << "Drew a " << ranks[r] << " of " << suit << endl;
		}
		
		
		if(r == rank)
			return true;
		else
			return false;
		//cout << "deck has this many cards left " << n_cards << endl;
	}
	else
	{
		cout << "This shouldn't have happened!" << endl;
		exit(0);
		// out of stock
		return false;
	}
}

void Deck::shuffle(){
	
		Card temp;
		for(int i = 0; i < 52; i++){
			int num = rand() % 52;
			temp = cards[i];
			cards[i] = cards[num];
			cards[num] = temp;
		}
		
}
void Deck::deal(Player* player, int num_cards){
	Hand* p_hand = player->getHand();	// this may be wrong
	for(int i = 0; i < num_cards; i++){
		p_hand->addCard(cards[n_cards-1]);
		n_cards--;
	
	}
	//cout << "deck has this many cards left " << n_cards << endl;
}