/* 
CS 341 - Assignment 4
Date: 10/22/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include "Node.h"

class LinkedNode : public Node
{
	public:
		LinkedNode();
		LinkedNode(Card data);
		~LinkedNode();
		LinkedNode * getNextLinkedNode();
		void setNextLinkedNode(LinkedNode * nextLinkedNode);
		bool hasNextLinkedNode();
		
		//phase 3
		LinkedNode * getPrevLinkedNode();
		void setPrevLinkedNode(LinkedNode * prevLinkedNode);
		bool hasPrevLinkedNode();

		
	private:
		LinkedNode * nextLinkedNode_; 
		LinkedNode * prevLinkedNode_;


};

#endif