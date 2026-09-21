/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "HashTableArray.h"

/// Constructor
HashTableArray::HashTableArray()
{
	
}

/// Destructor
HashTableArray::~HashTableArray()
{
	delete [] entry_;
}

HashTableArray::HashTableArray(const HashTableArray & array) : entry_(new HashEntry[array.size_]) , size_(array.size_), linear_(array.linear_)
{
	// take any dynamic allowed 
	for(int i =0;i<array.size_;i++)
	{
		entry_[i]= array.entry_[i];
	}	
}


HashTableArray::HashTableArray(int size)
{
	size_ = size;
	entry_ = new HashEntry[size_];
	linear_ = false;
	/*
	for(int i = 0; i < size_; i++)
	{
		entry_[i].setStatus(EMPTY);
	}
	*/
}

void HashTableArray::setProbingType(bool linear)
{
	linear_ = linear;
}

// check if quadratic or linear; use if statements to handle collisions
void HashTableArray::insert(int key, int value)
{
	HashEntry entry1 = HashEntry(key, value);
	
	bool isPlaced = false;
	int index = 0;
	int n = 0;
	
	while(!isPlaced)
	{
		if(linear_ == 1)
		{
			index = (key % size_ + n) % size_;
			
			if(index > size_-1)
			{
				index = index % size_;
			}
			
			if(entry_[index].getStatus() == EMPTY || entry_[index].getStatus() == REMOVED)
			{
				entry_[index] = entry1; 
				entry_[index].setStatus(OCCUPIED);
				isPlaced = true;
			}
			else
			{
				n++;
			}
		}
		else
		{
			index = (key % size_ + n^2);
			//std::cout << n << std::endl;
			
			if(index > size_-1)
			{
				index = index % size_;
			}
			
			if(entry_[index].getStatus() == EMPTY || entry_[index].getStatus() == REMOVED)
			{
				entry_[index] = entry1; 
				entry_[index].setStatus(OCCUPIED);
				
				//std::cout << key << " " << index << std::endl;
				
				isPlaced = true;
			}
			else
			{
				n++;
			}			
		}
	}
}

// takes the key, returns the number that is there; if not return 0
int HashTableArray::search(int key)
{
	bool found = false;
	int index = 0;
	int n = 0;
	int temp = 0;
	
	while(found == false)
	{
		if(linear_ == 1)
		{
			index = (key % size_ + n) % size_;
			
			if(entry_[index].getStatus() == EMPTY || entry_[index].getStatus() == REMOVED)
			{
				std::cout << "Key: " << entry_[index].getKey() << " Value: " << entry_[index].getValue() << std::endl;
				found = true;
				temp = entry_[index].getValue();
			}
			else
			{
				n++;
			}
		}
		else
		{
			index = (key % size_ + n*n) % size_;
			
			if(entry_[index].getStatus() == EMPTY || entry_[index].getStatus() == REMOVED)
			{
				std::cout << "Key: " << entry_[index].getKey() << " Value: " << entry_[index].getValue() << std::endl;
				found = true;
				temp = entry_[index].getValue();
			}
			else
			{
				n++;
			}			
		}
	}
	
	if(found != true)
	{
		std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
	}
	return temp;

}
	
// takes the key, goes to that key in the table, and then if it finds a value, remove it by setting the status to removed; if not then say it wasn't found
void HashTableArray::remove(int key)
{
	bool found = false;
	int index = 0;
	int n = 0;
	int temp = 0;
	
	while(found == false)
	{
		if(linear_ == 1)
		{
			index = (key % size_ + n) % size_;
			
			if(entry_[index].getStatus() == EMPTY || entry_[index].getStatus() == REMOVED)
			{
				found = true;
				std::cout << "Key " << entry_[index].getKey() << " removed." << std::endl;
				entry_[index].setKey(0);
				entry_[index].setValue(0);
				entry_[index].setStatus(REMOVED);
			}
			else
			{
				n++;
			}
		}
		else
		{
			index = (key % size_ + n*n) % size_;
			
			if(entry_[index].getStatus() == EMPTY || entry_[index].getStatus() == REMOVED)
			{
				found = true;
				std::cout << "Key " << entry_[index].getKey() << " removed." << std::endl;
				entry_[index].setKey(0);
				entry_[index].setValue(0);
				entry_[index].setStatus(REMOVED);
			}
			else
			{
				n++;
			}			
		}
	}
	
	if(found != true)
	{
		std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
	}
}

//	prints out the table
void HashTableArray::print()
{
	std::cout << "***********************************" << std::endl;
	
	for(int i = 0; i < size_; i++)
	{
		std::cout << "[" << i << "]: ";
		if(entry_[i].getStatus() == OCCUPIED)
		{
			std::cout << entry_[i].getKey();
		}		
		std::cout << std::endl;
	}
	
	std::cout << "***********************************" << std::endl;
}
