/* card.h
   Author: Cody Faircloth
   Date: 03/13/2024
*/

#include <string>

#ifndef CARD_H
#define CARD_H

class Card {
private:
	/*Private variables of Card objects
	-value: Holds numeric value; example: 11
	-name: Holds name; example: "Ace"
	-suit: Holds suit; example: "Spades"
	-active: Holds active statuse; example: active = true/ inactive = false*/
	int value;
	std::string name;
	std::string suit;
	bool active;

public:
	/*Public Functions of Card objects
	-See card.cpp for more information*/
	Card(int value, std::string name, std::string suit);
	int getValue();
	std::string getName();
	std::string getSuit();
	bool isActive();
	void setActive();
	void setValue(int value);
};

#endif
