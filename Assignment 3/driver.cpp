// CS 341 - Assignment 3
//
// Date: 10/3/25
//
// Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
//
// By: Katie Baumgartner and David Jefferson

#include <iostream> 
#include <fstream>
#include "bitarray.h" 
#include "set.h"
#include "dictionary.h"

int main()
{
	int position;
	
	BitArray A(4);
	char word[] = {'t', 'e', 's', 't'};
	A.initialize(word, 4);
	
	std::cout << std::endl;
	A.print();
	std::cout << std::endl;
	
	/*
	char a = 'r';	
	A.set8(a, 0);
	char b = 'y';
	A.set8(b, 1);
	char c = 'a';
	A.set8(c, 2);
	char d = 'n';
	A.set8(d, 3);

	A.print();
	std::cout << std::endl;
	*/
	
	//std::cout << bit.get(0) << std::endl;
	//std::cout << bit.get8(1) << std::endl;
	/*
	if(bit.flip(1) == true)
	{
		std::cout << "TRUE" << std::endl;
	}
	else
	{
		std::cout << "FALSE" << std::endl;
	}
	*/
	/*
	std::cout << std::endl;
	bit.print();
	std::cout << std::endl;
	
	std::cout << "0th Bit Set: False" << std::endl;
	std::cout << "0th Bit Set: True" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Setting 0th position to 1..." << std::endl;
	bit.set(0, 1);
	bit.print();
	std::cout << std::endl;
	
	std::cout << "Setting 10th position to 0..." << std::endl;
	bit.set(10, 0);
	bit.print();
	std::cout << std::endl;
	
	std::cout << "Complement:" << std::endl;
	bit.complement();
	bit.print();
	std::cout << std::endl;
	
	std::cout << "Clear BitArray:" << std::endl;
	bit.clear();
	bit.print();
	std::cout << std::endl;
	*/
	/*
	char word2[] = {'r', 'y', 'a', 'n'};
	
	Set B(4);
	B.initialize(word2, 4);
	
	Set C(4);
	C.initialize(word, 4);

	std::cout << "Cardinality: " << B.getCardinality() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Set Union (A U B): " << std::endl;
	C.setUnion(B);
	std::cout << std::endl;
	
	std::cout << "Set Intersection (A X B): " << std::endl;
	C.setIntersection(B);
	std::cout << std::endl;
	*/
	
	Dictionary D;
	D.initialize(word, 4);
	
	
	D.rank(32, 1);
	//D.rank_range(15, 31, 1);
	D.select(4, 1);
	//D.select_range(0, 15, 2, 1);
	std::cout << std::endl;
	
	std::cout << "Printing Lookup Table..." << std::endl;
	D.printLookupTable(std::cout);
	
	return 0;
}