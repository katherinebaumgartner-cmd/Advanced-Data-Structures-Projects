/* 
CS 341 - Assignment 6
Date: 12/12/2025
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "HashTableCuckoo.h"


HashTableCuckoo::HashTableCuckoo()
{
	size_ = 0;
	cycle_ = false;
	unPlaced_ = 0;
    entry_ = nullptr;
	entry2_ = nullptr;
	
	cycleCounter_ = nullptr;
	cycleCounter2_ = nullptr;
}

HashTableCuckoo::HashTableCuckoo(int size)
{	
	size_ = size;
	cycle_ = false;
	unPlaced_ = 0;
	entry_ = new HashEntry[size_];
	entry2_ = new HashEntry[size_];
	
	cycleCounter_ = new HashEntry[size_];
	cycleCounter2_ = new HashEntry[size_];
}

HashTableCuckoo::HashTableCuckoo(const HashTableCuckoo & array) : entry_(new HashEntry[array.size_]) ,entry2_(new HashEntry[array.size_]), size_(array.size_), cycleCounter_(array.cycleCounter_), cycleCounter2_(array.cycleCounter2_)
{
	// take any dynamic allowed 
	for(int i =0;i<array.size_;i++)
	{
		entry_[i]= array.entry_[i];
	}
	for(int i =0;i<array.size_;i++)
	{
		entry2_[i]= array.entry2_[i];
	}	
}

		
HashTableCuckoo::~HashTableCuckoo()
{
	delete [] entry_;
	delete [] entry2_;
	
	delete [] cycleCounter_;
	delete [] cycleCounter2_;
}
		
void HashTableCuckoo::insert(int key, int value)
{
	/*
	HashEntry entry1 = HashEntry(key, value);
	
	bool isPlaced = false;
	int index = 0;
	int n = 0;
	bool table1 = true;
	int maxNumLoops = size_*100;
	
	HashEntry temp;
	
	while((!isPlaced) && (n < maxNumLoops))
	{
		if(table1)
		{
			index = (key % size_);
			
			if(entry_[index].getStatus() == EMPTY || entry_[index].getStatus() == REMOVED)
			{
				entry_[index] = entry1; 
				entry_[index].setStatus(OCCUPIED);
				isPlaced = true;
			}
			else
			{
				temp = entry_[index];
			
				entry_[index] = entry1; 
				entry_[index].setStatus(OCCUPIED);
				
				entry1 = temp;
				key = entry1.getKey();
				
				table1 = false;
			}
		}
		
		else
		{			
			index = (key / size_) % size_;
			
			if(entry2_[index].getStatus() == EMPTY || entry2_[index].getStatus() == REMOVED)
			{
				entry2_[index] = entry1; 
				entry2_[index].setStatus(OCCUPIED);
				isPlaced = true;
			}
			else
			{
				temp = entry2_[index];
				
				entry2_[index] = entry1; 
				entry2_[index].setStatus(OCCUPIED);
				
				entry1 = temp;
				key = entry1.getKey();
				
				table1 = true;
			}
		}
		n++;
	}
	
	if(!isPlaced)
	{
		cycle_ = true;
		unPlaced_ = key;
	}*/
	
	HashEntry entry1 = HashEntry(key, value);
	
	bool isPlaced = false;
	int index = 0;
	int n = 0;
	bool table1 = true;
	
	bool stopCycle = false;
	
	HashEntry temp;
	
	while((!isPlaced) && (!stopCycle))
	{
		if(table1)
		{
			index = (key % size_);
			
			if(entry_[index].getStatus() == EMPTY || entry_[index].getStatus() == REMOVED)
			{
				entry_[index] = entry1; 
				entry_[index].setStatus(OCCUPIED);
				isPlaced = true;
			}
			else
			{
				n++;
				temp = entry_[index];
			
				entry_[index] = entry1; 
				entry_[index].setStatus(OCCUPIED);
				
				entry1 = temp;
				key = entry1.getKey();
				
				table1 = false;
				if((n % 2) == 0)
				{
					//std::cout << "blah" << std::endl;
					cycleCounter_[index] = entry1; 
					cycleCounter_[index].setStatus(OCCUPIED);
				}
				else
				{
					//std::cout << "blah2" << std::endl;
					cycleCounter2_[index] = entry1; 
					cycleCounter2_[index].setStatus(OCCUPIED);
				}
				
			}
		}
		
		else
		{			
			index = (key / size_) % size_;
			
			if(entry2_[index].getStatus() == EMPTY || entry2_[index].getStatus() == REMOVED)
			{
				entry2_[index] = entry1; 
				entry2_[index].setStatus(OCCUPIED);
				isPlaced = true;
			}
			else
			{
				temp = entry2_[index];
				
				entry2_[index] = entry1; 
				entry2_[index].setStatus(OCCUPIED);
				
				entry1 = temp;
				key = entry1.getKey();
				
				table1 = true;
			}
		}
		
		if(n >= 4)
		{
			for(int i = 0; i < size_; i++)
			{
				//std::cout << "test" << std::endl;
				if((cycleCounter_[i].getStatus() != EMPTY) && (cycleCounter2_[i].getStatus() != EMPTY))
				{
					if(cycleCounter_[i].getKey() == cycleCounter2_[i].getKey())
					{
						//std::cout << "test2" << std::endl;
						stopCycle = true;
						unPlaced_ = cycleCounter_[i].getKey();
					}
				}
				
			}
		}
	}
	
	if(!isPlaced)
	{
		cycle_ = true;
		//unPlaced_ = key;
	}

}
		
int HashTableCuckoo::search(int key)
{
	bool found = false;
	
	for(int i = 0; i < size_; i++)
	{
		if(entry_[i].getKey() == key)
		{
			found = true;
			std::cout << "Key: " << entry_[i].getKey() << " Value: " << entry_[i].getValue() << std::endl;
		}
	}
	
	if(found != true)
	{
		for(int i = 0; i < size_; i++)
		{
			if(entry2_[i].getKey() == key)
			{
				found = true;
				std::cout << "Key: " << entry2_[i].getKey() << " Value: " << entry2_[i].getValue() << std::endl;
			}
		}
	}
	
	if(found != true)
	{
		std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
		key = 0;
	}
	return key;
}
		
void HashTableCuckoo::remove(int key)
{
	bool found = false;
	
	for(int i = 0; i < size_; i++)
	{
		if(entry_[i].getKey() == key)
		{
			found = true;
			std::cout << "Key " << entry_[i].getKey() << " removed." << std::endl;
			entry_[i].setKey(0);
			entry_[i].setValue(0);
			entry_[i].setStatus(REMOVED);
		}
	}
	
	if(found != true)
	{
		for(int i = 0; i < size_; i++)
		{
			if(entry2_[i].getKey() == key)
			{
				found = true;
				std::cout << "Key " << entry2_[i].getKey() << " removed." << std::endl;
				entry2_[i].setKey(0);
				entry2_[i].setValue(0);
				entry2_[i].setStatus(REMOVED);
			}
		}
	}
	
	if(found != true)
	{
		std::cout << "Invalid key! Key " << key << " not found in table!" << std::endl;
	}
}
		
void HashTableCuckoo::print()
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
	
	std::cout << "***********************************" << std::endl;
	
	for(int i = 0; i < size_; i++)
	{
		std::cout << "[" << i << "]: ";
		if(entry2_[i].getStatus() == OCCUPIED)
		{
			std::cout << entry2_[i].getKey();
		}		
		std::cout << std::endl;
	}
	
	std::cout << "***********************************" << std::endl;
}

bool HashTableCuckoo::reHash()
{
	if(cycle_ == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int HashTableCuckoo::getUnPlaced()
{
	return unPlaced_;
}