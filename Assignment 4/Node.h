/* 
CS 341 - Assignment 4
Date: 10/22/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include <iostream>
#ifndef NODE_H
#define NODE_H
#include "card.h"

class Node
{
	public:
		Node();
		Node(Card data);
		~Node();
		Card getValue();
		void setValue(Card data);
		
	private:
		Card data_;
	
	
};

#endif