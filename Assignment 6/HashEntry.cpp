/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "HashEntry.h"
          
HashEntry::HashEntry()
{
	key_ = 0;
	value_ = 0;
	status_ = EMPTY;
}

HashEntry::HashEntry(int key, int value)
{
	key_ = key;
	value_ = value;
	status_ = EMPTY;
}

HashEntry::~HashEntry()
{
	
}

void HashEntry::setKey(int key)
{
	key_ = key;
}

int HashEntry::getKey()
{
	return key_;
}

void HashEntry::setValue(int value)
{
	value_ = value;
}

int HashEntry::getValue()
{
	return value_;
}

void HashEntry::setStatus(Status status)
{
	status_ = status;
}

Status HashEntry::getStatus()
{
	return status_;
}