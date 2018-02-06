/*********************************************************************
** Program Filename: Card.cpp
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

// an array containing the english words used to represent cards in singular form
std::string ranks[13] = {"two", "three", "four", "five", "six", "seven",
	"eight", "nine", "ten", "jack", "queen", "king", "ace"};
	
// an array containing the english words used to represent cards in plural form
std::string ranks_p[13] = {"twos", "threes", "fours", "fives", "sixes", "sevens",
	"eights", "nines","tens", "jacks", "queens", "kings", "aces"};

// an array containing the inputs used to represent cards in a players hand
std::string ranks_choice[13] = {" 2", " 3", " 4", " 5", " 6", " 7", 
	" 8", " 9"," 10", " J", " Q", " K", " A"};
	
Card::Card(){}

Card::Card(int r, int s){
	rank = r;
	suit = s;
}

void Card::initialize(int r, int s){
	rank = r;
	suit = s;
}

int Card::getRank(){return rank;}
int Card::getSuit(){return suit;}
bool Card::getIsBooked(){return booked;}
void Card::book(){booked = true;}

