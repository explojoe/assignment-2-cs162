/*********************************************************************
** Program Filename: gofish.cpp
** Author: Joshua Wentzel
** Date: 2/4/2018
** Description: Play Go Fish vs. the computer.
** Input: Playing cards to guess for.
** Output: Go Fish gameplay.
*********************************************************************/


#include <iostream>
#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Hand.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <unistd.h>

using namespace std;

// an array containing the english words used to represent cards
std::string ranks_p2[13] = {"twos", "threes", "fours", "fives", "sixes", "sevens",
	"eights", "nines","tens", "jacks", "queens", "kings", "aces"};

int main(int argc, char *argv[]){
	// initialize the game
	srand (time(NULL));	// randomize the seed so that games are random
	
	while(1){
		cout << "Welcome to Go Fish! This is the reel deal!" << endl;
		
		Game* game = new Game();
		
		Deck deck = game->getDeck();
		
		deck.shuffle();
		
		Player* player1 = game->getPlayer(0);	// player1 is human player
		Player* player2 = game->getPlayer(1);	// player2 is computer player
		
		//deal the initial cards
		deck.deal(player1,7);
		deck.deal(player2,7);
		
		// initialization complete, let the game begin!
		
		int cur_player = rand() % 2;
		
		cout << "Your books:" << endl;
		player1->printBooks();
		cout << "Computer's books:" << endl;
		player2->printBooks();
		bool endGameFlag = false;
		
		player1->checkForBooks(true);
		player2->checkForBooks(true);
		
		while(1){
			cout << endl << endl;
			cout << "--------------------------------" << endl;
			cout << endl;
			
			bool breakFlag = false;
			if(cur_player == 0){

				while(1){
					cout << "It is your turn." << endl << endl;
					cout << "Computer's books:" << endl;
					player2->printBooks();

					int rank = player1->askForChoice();
					if(rank == -1){
						cout << "Your are out of cards." << endl;
						cout << "Drawing top card and going again." << endl;
						deck.fishFor(player1,-1, true);
					}
					else
					{
						cout << "You guessed " << ranks_p2[rank] << "." << endl;
						bool stole = game->moveCardsFromToOf(true,rank);
						if(!stole){
							cout << "Go Fish!" << endl;
							bool gotWish = deck.fishFor(player1,rank, true);
							if(gotWish){
								cout << "Got your wish! Go again!" << endl;
							}
							else{
								breakFlag = true;
							}
						}
						else{
							cout << "Good guess. Go again!" << endl;
						}	
					}
					player1->checkForBooks(true);
					if(game->checkGameOver()){
						endGameFlag = true;
						break;
					}
					if(breakFlag)
					{
						break;
					}
				}
			}
			else
			{
				// computer's turn
				cout << "The computer is taking its turn." << endl;
				
				while(1){
					cout << "Computer's books:" << endl;
					player2->printBooks();
					cout << endl;
					cout << "Your books:" << endl << endl;
					player1->printBooks();
					int rank = player2->randPickCard();
					if(rank == -1){
						cout << "Computer is out of cards." << endl;
						cout << "Drawing top card and going again." << endl;
						deck.fishFor(player2,-1, true);
					}
					else{
						cout << "Computer guessed " << ranks_p2[rank] << "." << endl;
						bool stole = game->moveCardsFromToOf(false,rank);
						if(!stole){
							cout << "Go Fish!" << endl;
							bool gotWish = deck.fishFor(player2,rank, false);
							if(gotWish){
								cout << "Computer got its wish, going again." << endl;
							}
							else{
								breakFlag = true;
							}
						}
						else{
							cout << "Computer stole your " << ranks_p2[rank];
							cout << ", going again." << endl;
						}
					}
					player2->checkForBooks(false);				
					if(game->checkGameOver()){
						endGameFlag = true;
						break;
					}
					if(breakFlag)
					{
						break;
					}
				}
			}
			if(endGameFlag){
				break;
			}
			cur_player = (cur_player+1)%2;
		}
		// free the memory
		delete game;
		cout << "Would you like to play again?[Y/n]" << endl;
		char input;
		cin >> input;
		if(int(toupper(input)) != 'Y'){
			cout << "See you another time." << endl;
			break;
		}
		cout << endl << endl << endl;
		
	}
	return 0;
}