/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "HashTableChaining.h"

HashTableChaining::HashTableChaining()
{
	size_ = 0;
    entry_ = nullptr;
}

HashTableChaining::HashTableChaining(int size)
{
	size_ = size;
	entry_ = new DoublyLinkedList[size_];
}

HashTableChaining::HashTableChaining(const HashTableChaining & array) : entry_(new DoublyLinkedList[array.size_]) , size_(array.size_)
{
	// take any dynamic allowed 
	for(int i =0;i<array.size_;i++)
	{
		entry_[i]= array.entry_[i];
	}	
}


HashTableChaining::~HashTableChaining()
{
	delete [] entry_;
}

void HashTableChaining::insert(int key, int value)
{
	int index = key % size_;
	
	HashEntry temp;
	
	temp.setKey(key);
	temp.setValue(value);
	temp.setStatus(OCCUPIED);
	
	entry_[index].insert(temp);
}

int HashTableChaining::search(int key)
{
	int index = key % size_;
	
	return entry_[index].find(key);
}

void HashTableChaining::remove(int key)
{
	int index = key % size_;
	
	HashEntry temp;
	
	temp.setKey(key);
	temp.setValue(search(key));
	temp.setStatus(OCCUPIED);
	
	entry_[index].remove(temp);
}

void HashTableChaining::print()
{
	std::cout << "***********************************" << std::endl;
	
	for(int i = 0; i < size_; i++)
	{
		std::cout << "[" << i << "]: ";
		if(!entry_[i].isEmpty())
		{
			entry_[i].printList();
		}		
		std::cout << std::endl;
	}
	
	std::cout << "***********************************" << std::endl;
}