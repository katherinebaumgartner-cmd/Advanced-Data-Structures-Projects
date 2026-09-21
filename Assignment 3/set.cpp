// CS 341 - Assignment 3
//
// Date: 10/3/25
//
// Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
//
// By: Katie Baumgartner and David Jefferson

#include "set.h"
          
//Initializing constructor. Builds a BitArray instance of 'size.'
Set::Set(int size) : data_(BitArray(size))
{
	
}

Set::Set(char * word, int size) : data_(BitArray(size))
{
	data_.initialize(word, size);
}

/// Destructor
Set::~Set()
{
	
}	


//Initializes the underlying BitArray with a character array (word) and the size of the word (int).
void Set::initialize(char * word, int size)
{	
	data_.initialize(word, size);	
}

void Set::print()
{
	data_.print();
}

//Returns the cardinality of the set - here the cardinality is represented by the number of 1's in the underlying BitArray.
int Set::getCardinality() const
{
	int cardinality = 0;
	
	for(int j = 0; j < data_.length(); j++)
	{
		if(data_.get(j) == true)
		{
			cardinality++;
		}
	}
	
	return cardinality;
	
}
	  
//Returns a reference to the underyling BitArray data_
BitArray & Set::getData()
{
	return data_;
}	

//Computes the Union of "this" set (A) and B.
bool Set::setUnion(Set & B)
{
	if(data_.length() == B.data_.length()) //set equal to compare
	{
		Set C(data_.bytes());
		for(int i = 0; i < data_.length(); i++)
		{			
			if(data_.get(i) | B.data_.get(i)) //or for union
			{
				C.getData().set(i);
			}
			else
			{
				C.getData().set(i, 0);
			}
		
		}
		C.print();
		return true;
	}
	else
	{
		return false;
	}
}
		
// Computes the Intersection of "this" set (A) and B.
bool Set::setIntersection(Set & B)
{
	if(data_.length() == B.data_.length()) //set equal to compare
	{
		Set C(data_.bytes());
		for(int i = 0; i < data_.length(); i++) //and for intersection
		{			
			if(data_.get(i) & B.data_.get(i))
			{
				C.getData().set(i);
			}
			else
			{
				C.getData().set(i, 0);
			}
		
		}
		C.print();
		return true;
	}
	else
	{

		return false;
	}
}