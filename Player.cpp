/*********************************************************************
** Program Filename: Player.cpp
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

Player::Player(){
	n_books = 0;
	books = new int[13];
}

int Player::randPickCard(){
	int totalCards = hand.getNumCards();

	int ranksArray[13];
	
	hand.scanCards(ranksArray);

	if(hand.getNumCards() == 0){
		return -1;
	}

	int index;

	while(1){
		index = rand() % 13;
		if(ranksArray[index] > 0){
			return index;
		}
	}
}

void Player::checkForBooks(bool isPlayer){
	int ranksArray[13];
	
	hand.scanCards(ranksArray);

	for(int i = 0; i < 13; i++){
		if(ranksArray[i] > 0){
			if(ranksArray[i] == 4){
				hand.bookRank(i);
				books[n_books] = i;
				n_books++;
				ranksArray[i] = 0;
				if(isPlayer){
					cout << "You've created a book of " << ranks_p[i] << "." << endl;
				}
				else{
					cout << "The computer created a book of ";
					cout << ranks_p[i] << "." << endl;
				}
			}
		}
	}
}

void Player::printBooks(){
	for(int i = 0; i < n_books; i++){
		cout << " " << ranks_p[books[i]] << " ";
	}
	cout << endl;
}

int Player::getNumBooks(){return n_books;}

int Player::askForChoice(){
	int totalCards = hand.getNumCards();
	int ranksArray[13];
	
	hand.scanCards(ranksArray);
	while(1){
		cout << endl;
		cout << "Your books:" << endl << endl;
		printBooks();
		if(hand.getNumCards() == 0){
			return -1;
		}
		
		getHand()->printCards();
				
		cout << endl;
		cout << "Please choose a card to ask for." << endl;
		for(int i = 0; i < 13; i++){
			if(ranksArray[i] != 4){
				if(ranksArray[i] != 0){
					cout << ranks_choice[i];
				}
			}
		}
		cout << endl;
		char input;
		
		string in;
		cin >> in;
		
		if(in == "10"){
			in = "0";
		}
		else if(in == "1"){
			in = "0";
		}
		if(in.length() > 1){
			cout << "Please enter a valid rank." << endl;
			continue;
		}
		input = in.at(0);
		int num = int(toupper(input));
		int choice;
		bool flagLoop = false;
		switch(num){
			case int('2'):
			case int('3'):
			case int('4'):
			case int('5'):
			case int('6'):
			case int('7'):
			case int('8'):
			case int('9'):
				choice = input-50;
				break;
			case int('0'):
				choice = 8;
				break;
			case int('J'):
				choice = 9;
				break;
			case int('Q'):
				choice = 10;
				break;
			case int('K'):
				choice = 11;
				break;
			case int('A'):
				choice = 12;
				break;
			default:
				cout << "Please enter a valid rank." << endl;
				flagLoop = true;
				break;
		}
		if(flagLoop){
			continue;
		}
		if(ranksArray[choice] > 0){
			return choice;
		}
		else
		{
			cout << "Can't ask for what you don't have one of." << endl;
		}
	}
}

Hand* Player::getHand(){return &hand;}

Player::~Player(){
	delete [] books;
}

