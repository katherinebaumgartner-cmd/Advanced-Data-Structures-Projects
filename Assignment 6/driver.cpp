/* 
CS 341 - Assignment 5
Date: 11/5/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include <fstream>
#include <iostream>

#include "HashEntry.h"
#include "HashTable.h"
#include "HashTableArray.h"
#include "DoublyLinkedList.h"
#include "HashTableChaining.h"
#include "HashTableCuckoo.h"

int main()
{
	
	int value;
	int key;

	int choice = 0; 
	int choice2 = 0;
	int size;
	int searchKey = 0;
	int removeKey = 0;
	
	int numEntries = 0;
	
	while(choice != 5)
	{
		choice = 0;
		choice2 = 0;
		numEntries = 0;
		
		std::cout << "Welcome to Blue IV's Can of Who Hash!" << std::endl;
		
		std::cout << "1) Linear Probing" << std::endl;
		std::cout << "2) Quadratic Probing" << std::endl;
		std::cout << "3) Separate Chaining" << std::endl;
		std::cout << "4) Cuckoo Hashing" << std::endl;
		std::cout << "5) Quit Program" << std::endl;
		std::cout << std::endl;
		
		std::cout << "Please enter your choice: " << std::endl;
		std::cin >> choice;
		
		//linear
		if(choice == 1)
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: " <<std::endl;
			std::cin >> size;
			
			HashTableArray * table = new HashTableArray(size);
			table->setProbingType(true);
			
			std::ifstream in;
			in.open("data.txt");
			
			while(in >> key >> value)
			{
				numEntries++;
			}
			
			in.close();
			
			if(size < numEntries)
			{
				std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
				std::cout << std::endl;
				choice2 = 4;
			}
			else
			{
				std::ifstream in;
				in.open("data.txt");
				
				while(in >> key >> value)
				{
					table->insert(key, value);
				}	
				
				in.close();
				
				std::cout << std::endl;
				
				table->print();
			}
			
			while(choice2 != 4)
			{
				std::cout << std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				
				std::cout << std::endl;
				std::cout << "Please enter your choice: " << std::endl;
				std::cin >> choice2;
				
				//search
				if(choice2 == 1)
				{
					std::cout << "Search (Please enter a Key): ";
					std::cin >> searchKey;
					std::cout << std::endl;
					
					table->search(searchKey);
					std::cout << std::endl;
				}
				//remove
				else if(choice2 == 2)
				{
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> removeKey;
					std::cout << std::endl;
					
					table->remove(removeKey);
					std::cout << std::endl;
				}
				else if(choice2 == 3)
				{
					table->print();
				}
			}
			delete table; 
		}
		
		else if(choice == 2)
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: " <<std::endl;
			std::cin >> size;
			
			HashTableArray * table = new HashTableArray(size);
			table->setProbingType(false);
			
			std::ifstream in;
			in.open("data.txt");
			
			while(in >> key >> value)
			{
				numEntries++;
			}	
			
			in.close();
			
			if(size < numEntries)
			{
				std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
				std::cout << std::endl;
				choice2 = 4;
			}
			else
			{
				std::ifstream in;
				in.open("data.txt");
				
				while(in >> key >> value)
				{
					table->insert(key, value);
				}	
				
				in.close();
				
				std::cout << std::endl;
				
				table->print();
			}
			
			while(choice2 != 4)
			{
				std::cout << std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				
				std::cout << std::endl;
				std::cout << "Please enter your choice: " << std::endl;
				std::cin >> choice2;
				
				//search
				if(choice2 == 1)
				{
					std::cout << "Search (Please enter a Key): ";
					std::cin >> searchKey;
					std::cout << std::endl;
					
					table->search(searchKey);
					std::cout << std::endl;
				}
				//remove
				else if(choice2 == 2)
				{
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> removeKey;
					std::cout << std::endl;
					
					table->remove(removeKey);
					std::cout << std::endl;
				}
				else if(choice2 == 3)
				{
					table->print();
				}
			}
			delete table; 
		}
		else if(choice == 3)
		{
			std::cout << "Please enter the size of the Hash Table you wish to create: " << std::endl;
			std::cin >> size;
			
			HashTableChaining * table = new HashTableChaining(size);

			std::ifstream in;
			in.open("data.txt");
			
			while(in >> key >> value)
			{
				numEntries++;
			}	
			
			in.close();

			if(size <= 0)
			{
				std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
				std::cout << std::endl;
				choice2 = 4;
			}
			else
			{
				std::ifstream in;
				in.open("data.txt");
				
				while(in >> key >> value)
				{
					table->insert(key, value);
				}	
				
				in.close();
				
				std::cout << std::endl;
				
				table->print();
			}
			
			while(choice2 != 4)
			{
				std::cout << std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
				
				std::cout << std::endl;
				std::cout << "Please enter your choice: " << std::endl;
				std::cin >> choice2;
				
				//search
				if(choice2 == 1)
				{
					std::cout << "Search (Please enter a Key): ";
					std::cin >> searchKey;
					std::cout << std::endl;
					
					table->search(searchKey);
					std::cout << std::endl;
				}
				//remove
				else if(choice2 == 2)
				{
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> removeKey;
					std::cout << std::endl;
					
					table->remove(removeKey);
					std::cout << std::endl;
				}
				else if(choice2 == 3)
				{
					table->print();
				}
			}
			
			delete table; 
		}
		else if(choice == 4)
		{
			numEntries = 0;
			
			std::cout << "Please enter the size of the Hash Table you wish to create: " <<std::endl;
			std::cin >> size;
			
			HashTableCuckoo * table = new HashTableCuckoo(size);

			std::ifstream in;
			in.open("data.txt");
			
			while(in >> key >> value)
			{
				numEntries++;
			}
			
			in.close();
			
			if((numEntries/2) >= size)
			{
				std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
				std::cout << std::endl;
				choice2 = 4;
			}
			else
			{
				std::ifstream in;
				in.open("data.txt");
			
				while((in >> key >> value) && (!table->reHash()))
				{
					table->insert(key, value);
				}	
				
				in.close();
				
				if(table->reHash())
				{
					std::cout << std::endl;
					std::cout << "Cycle Present - ReHash!" <<std::endl;
					std::cout << "Key Unpositioned: " << table->getUnPlaced() << std::endl;
					std::cout << std::endl;
					std::cout << "<<<--- Insufficient Hash Table Size! Re-hash! --->>>" << std::endl;
					
					choice2 = 4;
				}
				else
				{
					table->print();
				}
				
				std::cout << std::endl;
			}
				
			while(choice2 != 4)
			{				
				std::cout << std::endl;
				std::cout << "1) Search For Entry" << std::endl;
				std::cout << "2) Remove Entry" << std::endl;
				std::cout << "3) Print Hash Table" << std::endl;
				std::cout << "4) Return to Main Menu" << std::endl;
					
				std::cout << std::endl;
				std::cout << "Please enter your choice: " << std::endl;
				std::cin >> choice2;
					
				//search
				if(choice2 == 1)
				{
					std::cout << "Search (Please enter a Key): ";
					std::cin >> searchKey;
					std::cout << std::endl;
						
					table->search(searchKey);
					std::cout << std::endl;
				}
				//remove
				else if(choice2 == 2)
				{
					std::cout << "Remove (Please enter a Key): ";
					std::cin >> removeKey;
					std::cout << std::endl;
						
					table->remove(removeKey);
					std::cout << std::endl;
				}
				else if(choice2 == 3)
				{
					table->print();
					std::cout << std::endl;
				}
			}
		
			delete table; 
		}
		else if((choice != 1) || (choice != 2) || (choice != 3) || (choice != 4) || (choice != 5))
		{
			std::cout << "That is not an option. Pick again." << std::endl;
			std::cout << std::endl;
		}
	}
	
	std::cout << "Thank you for using Blue IV's program - Goodbye!" << std::endl;

    return 0;
}