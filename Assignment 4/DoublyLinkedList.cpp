/* 
CS 341 - Assignment 4
Date: 10/22/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : LinkedList()
{
	
}

DoublyLinkedList::~DoublyLinkedList()
{

}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList & DLL)
{
	head_ = nullptr;
	tail_ = nullptr;
	
	LinkedNode * firstNode = new LinkedNode(DLL.head_->getValue());

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

void DoublyLinkedList::printList()
{
	LinkedNode * node = LinkedList::getHead();   
	
	if(node == nullptr)
	{
		std::cout << "The list is empty!" << std::endl;
	}
	else
	{
		while(node->hasNextLinkedNode())
		{
			std::cout << node->getValue().print() << "<-->";
			
			node = node->getNextLinkedNode();
		}
		std::cout << node->getValue().print() << std::endl;
	}
}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, Card data)
{
	LinkedNode * newNode = new LinkedNode(data);
	
	if(isEmpty() == true)
	{
		LinkedList::setHead(newNode);
		LinkedList::setTail(newNode);
	}
	else
	{
		node->setNextLinkedNode(newNode);
		newNode->setPrevLinkedNode(node);
		LinkedList::setTail(newNode);
	}
	
}