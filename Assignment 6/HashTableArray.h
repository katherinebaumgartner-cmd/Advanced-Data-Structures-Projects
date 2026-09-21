/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H

#include <iostream>

#include "HashTable.h"
#include "HashEntry.h"

class HashTableArray : public HashTable
{
	public:
		
		HashTableArray();
		HashTableArray(int size);
		
		HashTableArray(const HashTableArray & array);
		
		virtual ~HashTableArray();

		void insert(int key, int value);
		
		int search(int key);
		
		void remove(int key);
		
		void print();
		
		void setProbingType(bool linear);
		
	private:
		
		HashEntry * entry_;
		int size_;		
		bool linear_;
		
};

#endif