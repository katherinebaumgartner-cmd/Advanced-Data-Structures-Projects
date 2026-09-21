// CS 341 - ICA
//
// Date: 10/8/25
//
// Honor Pledge: I pledge that I have neither given nor received any help on this assignment
//
// By: Katie Baumgartner 
#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>



	//create a program that can find the duplicate letters in the following string: "butler bulldogs"

/*
	char a = 'a';
	std::cout << "a: " << std::bitset<8>(a) << std::endl;

	char b = 'b';
	std::cout << "b: " << std::bitset<8>(b) << std::endl;
	
	char c = 'c';
	std::cout << "c: " << std::bitset<8>(c) << std::endl;
	
	char x;
	
	char word[] = {'b', 'u', 't', 'l', 'e', 'r', 'b', 'u', 'l', 'l', 'd', 'o', 'g', 's'};
	
	x = c - a;
	
	std::cout << "'c' = 'a': " << std::bitset<8>(x) << std::endl;
	
	std::cout << std::endl;
	std::cout << word << std::endl;
	std::cout << std::endl;
	
	for(int i = 0; i < 14; i++)
	{
		std::cout << word[i] << ": " << std::bitset<8>(i) << std::endl;
	}
	
*/


std::vector<char> duplicates(std::string str);

int main()
{
	std::vector<char> dupes;
	
	std::string test = "butler bulldogs";
	
	dupes = duplicates(test);
	
	std::cout << "Duplicates: ";
	
	for(char x : dupes)
	{
		std::cout << x << " ";
	}
	
	std::cout << std::endl;

	return 0;
}

std::vector<char> duplicates(std::string str)
{
	int bitArray(0);
	
	std::vector<char> myDupes;
	
	for(int i; i < str.length(); i++)
	{
		int charIndex = str[i] - 'a';
		
		if((bitArray & (1 << charIndex)) > 0)
		{
			myDupes.push_back(str[i]); //push_back is append
		}
		
		bitArray = bitArray | (1 << charIndex);
		
	}
	
	return myDupes;
	
}