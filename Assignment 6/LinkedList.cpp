/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "LinkedList.h"

LinkedList::LinkedList() : head_(nullptr), tail_(nullptr)
{
	
}

LinkedList::~LinkedList()
{
	if(head_ != nullptr)
	{
		delete head_;
	}
}

LinkedList::LinkedList(const LinkedList & LL) : head_(nullptr), tail_(nullptr)
{	
	LinkedNode * firstNode = new LinkedNode(LL.head_->getValue());

	while(firstNode->hasNextLinkedNode())
	{
		if(head_ == nullptr)
		{
			head_ = firstNode;
			tail_ = firstNode;
		}
		else
		{
			insertLinkedNode(tail_ , firstNode->getValue()); // builds this link between the nodes
		}
		firstNode = firstNode->getNextLinkedNode();
	}
}

void LinkedList::insert(HashEntry data)
{	
	if(head_ == nullptr)
	{
		LinkedNode * newNode = new LinkedNode(data);
		head_ = newNode;
		tail_ = newNode;
	}
	else
	{
		insertLinkedNode(tail_ , data); // builds this link between the nodes
		//tail_ = newNode; //pointing at the new tail
	}
	
}

void LinkedList::printList()
{
	LinkedNode * node = head_;
	
	if(node == nullptr)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		while(node->hasNextLinkedNode())
		{
			std::cout << node->getValue().getKey() << "-->";
			node = node->getNextLinkedNode();
		}
		std::cout << node->getValue().getKey() << std::endl;
	}
}

bool LinkedList::isEmpty()
{
	if(head_ == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedList::getLength()
{
	int length = 0;
	LinkedNode * node = head_;
	
	if(isEmpty() == false)
	{
		length++;
		while(node->hasNextLinkedNode())
		{
			length++;
			
			node = node->getNextLinkedNode();
		}
	}
	
	std::cout<< "Length: " << length << std::endl;
	return length;
}

void LinkedList::setHead(LinkedNode * head)
{
	
	LinkedNode * node = head_;
	head_ = head;
	head_->setNextLinkedNode(node);
}

LinkedNode * LinkedList::getHead()
{
	return head_;
}

void LinkedList::setTail(LinkedNode * tail)
{
	//without this tail was pointing to nothing now it is pointing to tail
	if(tail_ == nullptr)
	{
		head_ = tail;
		tail_ = tail;
	}
	
	tail_ ->setNextLinkedNode(tail);
	tail_ = tail;
}

LinkedNode * LinkedList::getTail()
{
	return tail_;
}

void LinkedList::insertLinkedNode(LinkedNode * node, HashEntry data)
{
	LinkedNode * newNode = new LinkedNode(data);
	
	if(isEmpty() == true)
	{
		LinkedList::setHead(newNode);
		LinkedList::setTail(newNode);
	}
	else
	{
		if(node == getTail())
		{
			node->setNextLinkedNode(newNode);
			LinkedList::setTail(newNode);
		}
		else if(node == getHead()) //for head
		{
			newNode->setNextLinkedNode(node);
			LinkedList::setHead(newNode);
		}
		else
		{
			node->setNextLinkedNode(newNode);
		}
		
	}
}
