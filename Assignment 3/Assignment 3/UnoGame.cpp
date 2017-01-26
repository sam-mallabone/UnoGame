
#include "UnoGame.h"

UnoGame::UnoGame(unsigned int size, unsigned int numbers, unsigned int cardnum) //this constructor initializes all aspects of the game
{
	ofEachNum = cardnum;
	nNumbers = numbers;
	numCards = 4 * numbers * cardnum; //a variable(cardnum) to detetermine how many cards of each color and number. ie 2 Blue 5's
	initializeCards(numCards); //initializing cards
	_gameSize = size;
	_playerArray = new UnoPlayer[_gameSize]; //initializing the player array
	initializePlayers(); //initializing the players
	initializeHand(); //initializing the hands of the players
	
}

void UnoGame::initializeCards(unsigned int n)
{
	// make a bag add all the cards to it
	Bag<UnoCard> bag(n); 
	Color col[]{ RED, BLUE, YELLOW, GREEN };
	for (int t = 0; t < ofEachNum; t++) //creating a bag and populating it with cards using the enum's
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < nNumbers; j++)
			{
				bag.add(UnoCard(col[i], j+1));//the add function for putting the cards into the bag
			}
		}
	}
	//putting all the cards in the bad into a queue
	for (int i = 0; i < n; i++) {
		game.enqueue(bag.getOne());
	}
}

void UnoGame::initializePlayers()
{
	for (int i = 0; i < _gameSize; i++)
	{
		_playerArray[i]._playerID = i + 1; //initializing the player ID's
	}
}

void UnoGame::initializeHand()
{
	UnoCard j; //initializing the hands of the players

	for (int a = 0; a < _gameSize; a++) //looping through for the number of players in the game
	{
		for (int b = 0; b < nNumbers; b++) //looping through for the number of cards each player holds
		{
			j = game.dequeue();
			_playerArray[a].hand.insert(j); //inserting the cards into the players hand
			numCards--;
		}
	}


	faceUp = game.dequeue(); //initializing the starting face up card



	std::cout << "Starting Hands of the Players are:" << std::endl << std::endl; //printing the starting hands

	for (int i = 0; i < _gameSize; i++)
	{
		std::cout << _playerArray[i] << std::endl;
	}
	std::cout << "The starting Face Up card is: "; //print faceUp
	std::cout << faceUp << std::endl << std::endl;

}

bool UnoGame::playTurn()
{
	int continueGame = 0;
	if (game.isEmpty() == 1) //if the queue is empty, repopulate the queue from the stack
	{
		std::cout << "***repopulating the deck!***" << std::endl << std::endl;
		for (int d = 0; d < played.size(); d++)
		{
			game.enqueue(played.pop()); //poping elements off the stack and enqueueing them into the stack
			
		}
	}
	for (int h = 0; h < _gameSize; h++)
	{
		std::cout << _playerArray[h] << std::endl; //printing the players hand
		UnoCard check;
		UnoCard temp;
		int success = 0;
		int size = _playerArray[h].hand.getLength();

		for (unsigned int i = 1; i < size + 1; i++) //for loop for checking to see if the faceUp card's number matches any in the players hand
		{
			check = _playerArray[h].hand.retrieve(i);
			if (check._number == faceUp._number) //comparing the two numbers, only enters the if statement if it is true
			{
				temp = _playerArray[h].hand.remove(i); //remove the card with the number match
				played.push(faceUp); //add the old faceup card to the stack
				faceUp = temp; // the played card is now the faceUp card
				success = 1; //success set to one meaning a card was played(makes sure the other if statements arent entered)
				std::cout << "**Player " << h + 1 << " played " << temp <<"** " << std::endl << std::endl;
				break;
			}
		}
		if (success == 0)//enters this loop if a number match wasnt found
		{
			for (unsigned int j = 1; j < size + 1; j++)
			{
				check = _playerArray[h].hand.retrieve(j);
				if (check._color == faceUp._color) //checks the players hand for any color matches
				{
					temp = _playerArray[h].hand.remove(j);
					played.push(faceUp);
					faceUp = temp;
					success = 1;
					std::cout << "**Player " << h + 1 << " played " << temp << "**" << std::endl << std::endl;
					break;
				}
			}
		}

		if (_playerArray[h].hand.getLength() == 1) //checks to see if the player only has one card left
		{
			std::cout << "**Attention! Player " << h+1 << " only has one card left!**" << std::endl << std::endl;
		}
			

		if (success == 0) //if success still is zero, meaning there wasnt a matching number or color
		{
			UnoCard adder;
			adder = game.dequeue();
			_playerArray[h].hand.insert(adder);
			numCards--;
			std::cout << "**Player " << h + 1 << " had to draw a card!**" << std::endl << std::endl;
		}

		continueGame = isSolved(h); //checks to see if the player is out of cards
		if (continueGame == 1)
		{
			break;
		}

		std::cout << "The face up card is now: " << faceUp << std::endl << std::endl;
		
	}

	return continueGame;
}

bool UnoGame::isSolved(unsigned int a)
{
	
		if (_playerArray[a].hand.getLength() == 0) //enters the if statement if the player is out of cards and returns true
		{
			std::cout << "**UNO! Player " << a + 1 << " has won the Game!!!!**" << std::endl;
			return 1;
		}
	return 0; //otherwise just returns 0

}

