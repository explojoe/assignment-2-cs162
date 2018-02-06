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

Game::Game(){}
Player* Game::getPlayer(int index){
	return &players[index];
}
Deck Game::getDeck(){return cards;}



// move these into Game VVVVVVVVVVVVVVVVVVVV
bool Game::moveCardsFromToOf(bool playerIsStealing, int rank){
	Player* playerSrc;
	Player* playerDst;
	if(playerIsStealing){
		playerSrc = &players[1];
		playerDst = &players[0];
	}
	else{
		playerSrc = &players[0];
		playerDst = &players[1];
	}
	Hand* handSrc = playerSrc->getHand();
	Hand* handDst = playerDst->getHand();
	
	Card* CardsSrc = handSrc->getCards();
	Card* CardsDst = handDst->getCards();
	bool stoleFlag = false;
	//while(1){
		for(int i = 0; i < handSrc->getNumCards(); i++){
			if(CardsSrc[i].getRank() == rank){
				stoleFlag = true;
				//cout << "||||||||||||||||||||||Moved a " << ranks[rank] << endl;
				handDst->addCard(CardsSrc[i]);
				handSrc->removeCard(i);
				i--;
				//continue;
			}
		}
		//break;
	//}
	
	return stoleFlag;
}

bool Game::checkGameOver(){
	Player* p1 = &players[0];
	Player* p2 = &players[1];
	if(((p1->getNumBooks()) + (p2->getNumBooks())) == 13){
		cout << endl << endl << endl << endl;
		cout << "GAME OVER" << endl;
		
		cout << "Your books:" << endl;
		p1->printBooks();
		cout << endl;
		cout << "Computer's books:" << endl;
		p2->printBooks();
		cout << endl;
		
		if((p1->getNumBooks()) > (p2->getNumBooks())){
			cout << "You are the winner!" << endl;
		}
		else
		{
			cout << "You have lost the game!" << endl;
		}
		//freeMemory();
		return true;
		//exit(0);
	}
	return false;
}

//void Game::freeMemory(){
	//players[0].freeMemory();
	//players[1].freeMemory();
//}

Game::~Game(){
	//delete players[0];
	//delete players[1];
}

