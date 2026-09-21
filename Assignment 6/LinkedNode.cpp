/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "LinkedNode.h"

LinkedNode::LinkedNode() : nextLinkedNode_(nullptr), prevLinkedNode_(nullptr)//if i have a single node there is no next node
{
	
}

LinkedNode::LinkedNode(HashEntry data) : Node(data), nextLinkedNode_(nullptr), prevLinkedNode_(nullptr)
{
		
}

LinkedNode::~LinkedNode()
{
	if(hasNextLinkedNode())
	{
		delete nextLinkedNode_;
	}

}

LinkedNode * LinkedNode::getNextLinkedNode()
{
	if(hasNextLinkedNode())
	{
		return nextLinkedNode_;
	}
	
	return nullptr;
}

void LinkedNode::setNextLinkedNode(LinkedNode * LinkedNode)
{
	nextLinkedNode_ = LinkedNode;
}

bool LinkedNode::hasNextLinkedNode()
{
	if(nextLinkedNode_ == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

LinkedNode * LinkedNode::getPrevLinkedNode()
{
	if(hasPrevLinkedNode())
	{
		return prevLinkedNode_;
	}
	
	return nullptr;
}

void LinkedNode::setPrevLinkedNode(LinkedNode * prevLinkedNode)
{
	prevLinkedNode_ = prevLinkedNode;
}

bool LinkedNode::hasPrevLinkedNode()
{
	if(prevLinkedNode_ == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}
