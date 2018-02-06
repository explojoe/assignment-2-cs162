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
std::string ranks[13] = {"two", "three", "four", "five", "six", "seven",
	"eight", "nine", "ten", "jack", "queen", "king", "ace"};
std::string ranks_p[13] = {"twos", "threes", "fours", "fives", "sixes", "sevens",
	"eights", "nines","tens", "jacks", "queens", "kings", "aces"};
	
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

