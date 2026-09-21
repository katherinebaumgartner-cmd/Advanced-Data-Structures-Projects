/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include <iostream>
#ifndef NODE_H
#define NODE_H
#include "HashEntry.h"

class Node
{
	public:
		Node();
		Node(HashEntry data);
		virtual ~Node();
		virtual HashEntry getValue();
		
	private:
		HashEntry data_;
	
	
};

#endif