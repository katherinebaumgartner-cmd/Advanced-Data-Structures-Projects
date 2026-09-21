/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef HASHTABLECUCKOO_H
#define HASHTABLECUCKOO_H

#include <iostream>

#include "HashTable.h"
#include "HashEntry.h"

class HashTableCuckoo
{
	public:
			
		HashTableCuckoo();
		HashTableCuckoo(int size);
		 HashTableCuckoo(const HashTableCuckoo & array);

		
		~HashTableCuckoo();
		
		void insert(int key, int value);
		
		int search(int key);
		
		
		void remove(int key);
		
		void print();
		
		bool reHash();
		
		int getUnPlaced();
		
	private:
		
		HashEntry * entry_; //Table I
		HashEntry * entry2_; //Table II
		int size_;
		bool cycle_; 
		int unPlaced_;
		
		HashEntry * cycleCounter_;
		HashEntry * cycleCounter2_;
};

#endif