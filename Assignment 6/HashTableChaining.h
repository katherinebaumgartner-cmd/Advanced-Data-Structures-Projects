/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H

#include <iostream>

#include "HashTable.h"
#include "DoublyLinkedList.h"
#include "HashEntry.h"

class HashTableChaining
{
	public:
		
		HashTableChaining();
		HashTableChaining(int size);
		
		HashTableChaining(const HashTableChaining & array);

		~HashTableChaining();
		
		void insert(int key, int value);
		
		int search(int key);
		
		void remove(int key);
		
		void print();
		
	private:
		
		DoublyLinkedList * entry_;
		int size_;
		
};

#endif