#pragma once
#include <string>
#include <iostream>
#include"OrderedList.h"
#include"UnoCard.h"
#include"Bag.h"
#include"Queue.h"
#include"StandardFunctors.h"


class UnoPlayer
{
public:
	OrderedList<UnoCard, IsLess> hand;
	int _playerID;
	UnoPlayer()
	{
		_playerID = 11;
	}
	UnoPlayer(int b)
	{
		_playerID = b;
	}
	~UnoPlayer() {}

	inline friend std::ostream& operator<< (std::ostream& os, const UnoPlayer& UP); //overloaded << operator declaration
};


std::ostream& operator<< (std::ostream& os, const UnoPlayer& UP) //the function definition of overloading the << operator
{
	//prints the players ID
	std::cout << "Player ";
	os << UP._playerID;
	std::cout << "'s hand contains the cards: " << std::endl;

	//prints the players full hand
	for (int i = 0; i < UP.hand.getLength(); i++)
	{
		os << UP.hand.retrieve(i + 1) << std::endl;
	}

	return os;
}