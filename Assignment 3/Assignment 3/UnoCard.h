#pragma once
#include <iostream>
#include <string>


enum Color{RED = 11, BLUE = 12, YELLOW = 13, GREEN = 14}; //enum for the colours


class UnoCard 
{
public:
	Color _color;
	
	int _number;
public:

	UnoCard() //default constructor for UnoCard
	{
		_color = RED;
		_number = 1;
	}

	UnoCard(Color color, int number ) //defined contructor
	{
		_color = color;
		_number = number;
	}

	~UnoCard() {}

	inline Color getColor(void) const { return _color; }
	inline int getNumber(void) const { return _number; }
	

	char toCharColor(void); // returns a char that "describes" card's suit
	friend std::ostream& operator<<(std::ostream& os, const UnoCard &c);
	inline friend bool operator<(const UnoCard& a, const UnoCard& b); //overloaded operator declarations
	inline friend bool operator>(const UnoCard& a, const UnoCard& b);
	inline friend bool operator==(UnoCard& a, UnoCard& b);

};

//checks to see if one card is less than the other
inline bool operator<(const UnoCard& a, const UnoCard& b) {
	if (a.getColor() == b.getColor()) return (a.getNumber()<b.getNumber());
	else                            return (a.getColor()<b.getColor());
}
//checks to see if one card is greater than the other
inline bool operator>(const UnoCard& a, const UnoCard& b) {
	if (a.getColor() == b.getColor()) return (a.getNumber()>b.getNumber());
	else                            return (a.getColor()>b.getColor());
}

// checks equality of suits and denominations for two cards
inline bool operator==(UnoCard& a, UnoCard& b) { return (a.getNumber() == b.getNumber() && a.getColor() == b.getColor()); }
