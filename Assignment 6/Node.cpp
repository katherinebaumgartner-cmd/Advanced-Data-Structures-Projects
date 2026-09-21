/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "Node.h"


Node::Node()
{
	
}

Node::Node(HashEntry data): data_(data)
{
	
}

Node::~Node()
{
	
}

HashEntry Node::getValue()
{
	return data_;
}
