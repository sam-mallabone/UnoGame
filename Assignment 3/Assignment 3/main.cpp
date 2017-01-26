#include<iostream>
#include<iomanip>
#include<ctime>
#include<memory>
#include<string>
#include "Bag.h"
#include "UnoCard.h"
#include "Queue.h"
#include "UnoPlayer.h"
#include "UnoGame.h"
#include "Stack.h"

using namespace std;

int main()
{
	//My code needs the List and OrderedList that I submitted for the repopulating the deck function to work properly
	//These are the versions that were provided
	cout << "*** Welcome to UNO! ***" << endl << endl;
	cout << "***Initializing the Game***" << endl << endl;
	srand(time(NULL)); //to make sure rand() is truly random
	UnoGame Uno(3,5); //initilizing the game. 3 players of 5 cards in their hand
	int ContinueGame = 0;//variable for checking if a player has won the game
	
	do {

		ContinueGame = Uno.playTurn(); //playTurn returns true if a player has won the game and this will cause the program to exit the do-while loop
		
	} while (ContinueGame != 1);
	
	cout << "Thank you for playing UNO! Have a nice day!" << endl << endl;

	return 0;

}
