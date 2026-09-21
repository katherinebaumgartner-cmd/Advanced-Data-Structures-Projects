// CS 341 - Assignment 3
//
// Date: 10/3/25
//
// Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
//
// By: Katie Baumgartner and David Jefferson

#include "dictionary.h"
          
// Constructor
Dictionary::Dictionary() : data_(0)
{
	lookupTable_ = nullptr;
}	
		
//copy constructor
Dictionary::Dictionary (const Dictionary & dict)
{
	data_ = dict.data_;
	lookupTable_ = new int [DICTIONARY_SIZE];
}
		
// Destructor
Dictionary::~Dictionary()   
{
	delete [] lookupTable_;
}

//Initializes the underlying BitArray with a character array (word) and the size of the word (int).
void Dictionary::initialize(char * word, int size)
{
	data_.initialize(word, size);
	initializeDict();
}

//Returns how many of the bit b are in the interval [start,end).
int Dictionary::rank_range(int start, int end, int bit)
{
	int count = 0;
	
	//error catching
	if(end > data_.length())
	{
		return -1;
	}
	if(end < 0)
	{
		return -1;
	}
	if(start < 0)
	{
		return -1;
	}
	
	//rank_range code
	for(int i = start; i < end; i++)
	{
		if(data_.get(i) == bit)
		{
			count++;
		}		
	}
	
	//print statement and return
	std::cout<< "Rank Range: (" << start << ", " << end << ", " << bit << ") : " << count << std::endl;
	return count;
}


//Returns how many of the bit b are in the interval [0,end).
int Dictionary::rank(int end, int bit)
{
	int count = 0;
	int byteIndex = 0;
	int i = 0;
	int fullBytes = end / BIT_IN_BYTE;
	
	//error catching
	if(end > data_.length())
	{
		return -1;
	}
	if(end < 0)
	{
		return -1;
	}
	
	//rank code
	if(bit == 1) //when bit = 1
	{
		for(int i = 0; i < fullBytes; i++) //for loop used to see how many full bytes are in the interval
		{
			count += lookupTable_[data_.get8(byteIndex)];
			byteIndex += BIT_IN_BYTE;
		}
	}
	
	else //when bit is 0
	{
		for(int i = 0; i < fullBytes; i++)
		{
			count += BIT_IN_BYTE - lookupTable_[data_.get8(byteIndex)];
			byteIndex += BIT_IN_BYTE;
		}	
	}
	
	//extra bits that arent in a full byte
	for(int i = fullBytes * BIT_IN_BYTE; i < end; i++)
	{
		if(data_.get(i) == bit)
		{
			count++;
		}
	}
	
	//print rank
	std::cout<< "Rank: " << count << std::endl;
	return count;
}

// Returns the position of the kth bit b in the interval [start,end).
int Dictionary::select_range(int start, int end, int k, int bit)
{
	int position = start;
	int count = 0;
	
	//error catching
	if(end > data_.length())
	{
		return -1;
	}
	if(end < 0)
	{
		return -1;
	}
	if(start < 0)
	{
		return -1;
	}
	
	//select_range code
	//while loop runs while count < k and position < end
	while((count < k) && (position < end))
	{
		if(data_.get(position) == bit)
		{
			count++;			
		}		
		position++;
	}
	
	//error catching
	if(count == k)
	{
		std::cout << "Select Range: (" << start << ", " << end << ", " << k << ", " << bit << ") : " << position-1 << std::endl;

		//position-1 b/c the while loop adds the last position before the loop ends
		return position-1;
	}
	else
	{
		return -1;
	}
	
}

//Returns the position of the kth bit b in the interval [start,end).
int Dictionary::select(int k, int bit)
{
	int position = 0;
	int count = 0;
	
	//error catching
	if(k < 0)
	{
		return -1;
	}
	
	//select code
	//when bit == 1
	if(bit == 1)
	{
		while(count < k)
		{	
			//error catching
			if(position > data_.length())
			{
				return -1;
			}
			
			count += lookupTable_[data_.get8(position)];
			position += BIT_IN_BYTE;
		}
		position -= BIT_IN_BYTE;
		count -= lookupTable_[data_.get8(position)];
	}

	//when bit == 0
	else
	{
		while(count < k)
		{	
			//error catching
			if(position > data_.length())
			{
				return -1;
			}
			
			count += BIT_IN_BYTE - lookupTable_[data_.get8(position)];
			position += BIT_IN_BYTE;
		}
		position -= BIT_IN_BYTE;
		count -= BIT_IN_BYTE - lookupTable_[data_.get8(position)];
	}
	
	//extra bits that arent in a full byte
	while(count < k)
	{	
		if(data_.get(position) == bit)
		{
			count++;
		}
		position++;
	}

	std::cout << "Select: (" << k << ", " << bit << ") : " << position-1 << std::endl;
	
	//position-1 b/c the while loop adds the last position before the loop ends
	return position-1;
}

// Uses an output stream to write the contents of the Lookup Table.
void Dictionary::printLookupTable(std::ostream & output)
{
	for(int i = 0; i < DICTIONARY_SIZE; i++)
	{
		output << "lookupTable_[" << i << "] : " << lookupTable_[i] << std::endl;
	}
}

//initialize helper function
void Dictionary::initializeDict()
{
	lookupTable_ = new int [DICTIONARY_SIZE];
	Set temp(1);
	char tempChar[1];
	
	for(int i = 0; i < DICTIONARY_SIZE; i++)
	{
		tempChar[0] = i;
		temp.initialize(tempChar, 1);
		lookupTable_[i] = temp.getCardinality();
	}
}