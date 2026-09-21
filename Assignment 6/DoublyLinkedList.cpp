/* 
CS 341 - Assignment 6
Date: 12/12/2025
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
			std::cout << node->getValue().getKey() << "<-->";
			
			node = node->getNextLinkedNode();
		}
		std::cout << node->getValue().getKey();
	}
}

void DoublyLinkedList::insertLinkedNode(LinkedNode * node, HashEntry data)
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

void DoublyLinkedList::remove(HashEntry data)
{
	LinkedNode * current = head_;
    while (current != nullptr)
    {
        if (current->getValue().getKey() == data.getKey())
        {
            LinkedNode * prev = current->getPrevLinkedNode();
            LinkedNode * next = current->getNextLinkedNode();

            if (prev != nullptr)
            {
                prev->setNextLinkedNode(next);
            }
            else
            {
                head_ = next; // removing head
            }

            if (next != nullptr)
            {
                next->setPrevLinkedNode(prev);
            }
            else
            {
                tail_ = prev; // removing tail
            }

            current->setNextLinkedNode(nullptr);
            current->setPrevLinkedNode(nullptr);

            delete current;
            return;
        }
        current = current->getNextLinkedNode();
    }
}

int DoublyLinkedList::find(int key)
{
	if(isEmpty())
	{
		return 0;
	}
	else
	{
		LinkedNode * currentNode = LinkedList::getHead();
		
		while(currentNode != nullptr)
		{
			if(key == currentNode->getValue().getKey())
			{
				std::cout << "Key: " << currentNode->getValue().getKey() << " Value: " << currentNode->getValue().getValue() << std::endl;
				
				return currentNode->getValue().getKey();
			}
			else
			{
				currentNode = currentNode->getNextLinkedNode();
			}
		}
		return 0;
	}
	
}