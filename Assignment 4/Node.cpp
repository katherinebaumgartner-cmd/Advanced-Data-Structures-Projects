/* 
CS 341 - Assignment 4
Date: 10/22/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "Node.h"


Node::Node()
{
	Card def = Card(0, 0);
	data_ = def;
}

Node::Node(Card data): data_(data)
{
	
}

Node::~Node()
{
	
}

Card Node::getValue()
{
	return data_;
}

void Node::setValue(Card data)
{
	data_ = data;
}
