/* card.cpp
   Author: Cody Faircloth
   Date: 03/13/2024
*/
#include "card.h"

/*Card Object Constructor
-gives each Card object the corresponding value name and suit
-active keeps track of if the cards been dealt(all cards are active by default*/
Card::Card(int value, std::string name, std::string suit) {
	this->value = value;
	this->name = name;
	this->suit = suit;
	active = true;
}

/*Retrieves the int value of a Card object*/
int Card::getValue() {
	return this->value;
}

/*Retrieves the name of the Card object*/
std::string Card::getName() {
	return this->name;
}

/*Retrieves the suit of the Card object*/
std::string Card::getSuit() {
	return this->suit;
}

/*Retrieves the active status of the Card object*/
bool Card::isActive() {
	return this->active;
}

/*Changes active status of the Card object
active -> inactive / inactive -> active*/
void Card::setActive() {
	if (this->active) {
		this->active = false;
	}
	else {
		this->active = true;
	}
}

/*Changes the int value of a card
-Only used to change Ace values from 11 to 1 when necessary
-Changes Ace back to 11 on deck reset*/
void Card::setValue(int value) {
	this->value = value;
}