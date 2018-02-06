/*********************************************************************
** Program Filename: Game.cpp
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

Game::Game(){}

Player* Game::getPlayer(int index){
	return &players[index];
}

Deck Game::getDeck(){return cards;}

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
	for(int i = 0; i < handSrc->getNumCards(); i++){
		if(CardsSrc[i].getRank() == rank){
			stoleFlag = true;
			handDst->addCard(CardsSrc[i]);
			handSrc->removeCard(i);
			i--;
			//continue;
		}
	}
	
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
		
		return true;
	}
	return false;
}

Game::~Game(){}

