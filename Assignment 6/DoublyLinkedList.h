/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "LinkedList.h"
#include "HashEntry.h"

class DoublyLinkedList : public LinkedList
{
	public:
		DoublyLinkedList();
		DoublyLinkedList(const DoublyLinkedList & DLL);
		
		virtual ~DoublyLinkedList();	
		virtual void printList();
		void remove(HashEntry data);
		int find(int key);
		
		void insertLinkedNode(LinkedNode * node, HashEntry data);	
};

#endif