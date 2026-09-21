/* 
CS 341 - Assignment 4
Date: 10/22/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LinkedList.h"
#include "LinkedNode.h"
#include <iostream>
#include "card.h"

class DoublyLinkedList : public LinkedList
{
	public:
		DoublyLinkedList();
		~DoublyLinkedList();	
		DoublyLinkedList(const DoublyLinkedList & DLL);
	
		virtual void printList();
		
	private:
		void insertLinkedNode(LinkedNode * node, Card data);
	
};

#endif