// CS 341 - Assignment 3
//
// Date: 10/3/25
//
// Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
//
// By: Katie Baumgartner and David Jefferson

#include "bitarray.h"
          
// void print()
void BitArray::print()
{	
	std::cout << "|";
	
	for (int i=0; i < BYTES; i++)
	{
		std::bitset <BIT_IN_BYTE> bits = data_[i];
		std::cout << bits << "|";
	}
	
	std::cout << std::endl;	
}

//Initializing constructor
BitArray::BitArray(int size)
{
	LENGTH = size;
	data_ = NULL;
	BYTES = LENGTH/BIT_IN_BYTE;
}

//Copy constructor
BitArray::BitArray(const BitArray & array)
{
	LENGTH = array.LENGTH;
	BYTES = array.BYTES;
	
	data_ = new char [BYTES]; //each char is 8 bits
	
	for(int i = 0; i < BYTES; i++)
	{
		data_[i] = array.data_[i];
	}
}

/// Destructor
BitArray::~BitArray()
{
	delete [] data_;
}

bool BitArray::get(int position) const
{	

	if((data_[position / 8] >> (7-(position % 8))) & 1)
	{
		//std::cout << data_[position/8] << std::endl;
		return true;
	}
	else
	{
		return false;
	}
	
}

//Initializes the BitArray with a character array 
void BitArray::initialize(char * word, int size)
{	
	LENGTH = size;
	BYTES = LENGTH/BIT_IN_BYTE;
	data_ = new char [BYTES];
	
	for(int i = 0; i < BYTES; i++)
	{
		data_[i] = word[i];
	}
}

//Flips the bit at the specified position: 1->0, 0->1.
bool BitArray::flip(int position)
{
	int byteIndex = position / BIT_IN_BYTE;
	int bitIndex = (7-(position % 8));
	
	data_[byteIndex] ^= (1 << bitIndex);
	return true;
	
}

//Sets a bit value (default: 1) at the specified position.
bool BitArray::set(int position, int bit)
{
	if(position > LENGTH)
	{
		return false;
	}
	else
	{
		int byteIndex = position / BIT_IN_BYTE;
		int bitIndex = (7-(position % 8));
		
		if(bit == 0) // if bit = 0 turns it into 1
		{
			data_[byteIndex] ^= (1 << bitIndex);
		}
		else // if bit = 1 leaves it as 1
		{
			data_[byteIndex] |= (1 << bitIndex);
		}
		
		return true;
	}
}

//Returns the character in the byte (8 bits) within the BitArray given a specified position
char BitArray::get8(int position) const
{
	return data_[(position / BIT_IN_BYTE)];
	
}

// Flips the 1's and 0's in the BitArray.
void BitArray::complement()
{
	for(int i = 0; i < LENGTH; i++)
	{
		flip(i);
	}
}


// Sets all of the bits to 0.
void BitArray::clear()
{
	char zero = 0;
	for(int i = 0; i < BYTES; i++)
	{
		data_[i] = zero;
	}
}
