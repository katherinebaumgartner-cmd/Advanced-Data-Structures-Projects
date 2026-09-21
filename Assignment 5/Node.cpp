/* 
CS 341 - Assignment 5
Date: 11/5/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "Node.h"


Node::Node()
{

}

Node::Node(int data): data_(data)
{
	
}

Node::~Node()
{
	
}

int Node::getValue()
{
	return data_;
}

void Node::setValue(int data)
{
	data_ = data;
}
