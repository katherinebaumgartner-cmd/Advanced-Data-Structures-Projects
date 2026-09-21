/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedNode.h"
#include "HashEntry.h"
#include <iostream>

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		LinkedList(const LinkedList & LL);
		
		bool isEmpty();
		int getLength();
		void insert(HashEntry data);
		void printList();
		void setHead(LinkedNode * head);
		LinkedNode * getHead();
		void setTail(LinkedNode * tail);
		LinkedNode * getTail();
		
		
	protected:
		virtual void insertLinkedNode(LinkedNode * node, HashEntry data);
		LinkedNode * head_;
		LinkedNode * tail_;



};

#endif