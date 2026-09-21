/* 
CS 341 - Assignment 4
Date: 10/22/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "DawgHops.h"

dawgHops::dawgHops()
{
	
}

dawgHops::~dawgHops()
{
	
}

void dawgHops::insertionSort(DoublyLinkedList * dll, int & dawgHops)
{
	if(dll->getHead() != nullptr) //make sure list isnt empty
	{
		LinkedNode * A = dll->getHead()->getNextLinkedNode(); //sets A to 2nd node in the dll
		
		while (A != nullptr) //while there are still nodes (doesn't go past tail)
		{
			LinkedNode * C = A;
			LinkedNode * B = A->getPrevLinkedNode();

			while ((B != nullptr) && (B->getValue().getFaceVal() > C->getValue().getFaceVal())) //doesn't go before the head && B > C
			{
				//use card values to swap not nodes
				Card temp = B->getValue();
				
				B->setValue(C->getValue()); 
				
				C->setValue(temp);
				
				//checks the earlier nodes
				C = B;
				B = B->getPrevLinkedNode(); //makes B = nullptr to break out of while loop
				dawgHops++;
			}
			
			//moves to next unsorted node after sorting the current node
			A = A->getNextLinkedNode();
		}
	}	
}