/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef HASHENTRY_H
#define HASHENTRY_H

#include <iostream>

enum Status
{
	EMPTY,
	OCCUPIED,
	REMOVED,
};

class HashEntry
{
	public:
	
		HashEntry();
		HashEntry(int key, int value);
		
		~HashEntry();
		
		void setKey(int key);
		int getKey();
		
		void setValue(int value);
		int getValue();
		
		void setStatus(Status status);
		Status getStatus();
		
	private:
		
		int key_;
		int value_;
		Status status_;
	
};

#endif