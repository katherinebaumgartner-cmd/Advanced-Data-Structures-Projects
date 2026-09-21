/* 
CS 341 - Assignment 5
Date: 11/5/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include <iostream>
#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		Node();
		Node(int data);
		~Node();
		int getValue();
		void setValue(int data);
		
	private:
		int data_;
	
	
};

#endif