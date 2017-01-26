#include"UnoCard.h"

char UnoCard::toCharColor() //converting the colors into characters
{
	if (_color == RED)   return 'R';
	else if (_color == BLUE)    return 'B';
	else if (_color == GREEN)   return 'G';
	else if (_color == YELLOW)   return 'Y';
}


std::ostream& operator<<(std::ostream& os, const UnoCard &c) { //overloading the << operator so it can print the cards
	int color = c.getColor(); //get functions for colour and number
	int number = c.getNumber();

	switch (color) { //switch statement for printing the correct colour
	case 11:
		os << "Red ";
		break;
	case 12:
		os << "Blue ";
		break;
	case 13:
		os << "Yellow ";
		break;
	case 14:
		os << "Green ";
	}

	os << number;

	return os;
}
