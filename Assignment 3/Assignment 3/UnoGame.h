#pragma once
#include<iostream>
#include<iomanip>
#include<ctime>
#include<memory>
#include<string>
#include "Bag.h"
#include "UnoCard.h"
#include "Queue.h"
#include "UnoPlayer.h"
#include "List.h"
#include "Stack.h"
#define DEFAULT_PLAYERS 3
#define DEFAULT_NUMBER 5
#define DEFAULT_EACH_NUM 2



class UnoGame
{
public:
	UnoPlayer * _playerArray; //list of all member variables
	Queue<UnoCard> game;
	Stack<UnoCard> played;
	UnoCard faceUp;
	int _gameSize;
	unsigned int numCards;
	int nNumbers;
	int stackSize;
	int ofEachNum;
	
	UnoGame(unsigned int size = DEFAULT_PLAYERS, unsigned int numbers = DEFAULT_NUMBER, unsigned int cardnum = DEFAULT_EACH_NUM); 
	//constructor with default values if none are inputted when initialized
	

	void initializeCards(unsigned int n); //function declarations
	void initializePlayers();
	void initializeHand();
	bool playTurn();
	bool isSolved(unsigned int a);
	
};





