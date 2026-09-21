/* 
CS 341 - Assignment 4
Date: 10/22/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "card.h"

std::string Card::SUIT[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};

std::string Card::FACE[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card() //default constructor
{
	
}
	
Card::Card(int suitVal, int faceVal)
{
	suitVal_ = suitVal;
	faceVal_ = faceVal;
}

Card::~Card()
{
	
}

std::string Card::getSuit()
{
	return SUIT[suitVal_];
	
}

std::string Card::getFace()
{
	return FACE[faceVal_];
}

std::string Card::print()
{
	std::string print;
	
	print = getFace() + " of " + getSuit();
	
	return print;

}

void Card::initialize(int suitVal, int faceVal)
{
	suitVal_ = suitVal;
	faceVal_ = faceVal;
}

int Card::getFaceVal()
{
	return faceVal_;
}