/* 
CS 341 - Assignment 4
Date: 10/22/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "LinkedNode.h"
#include "Node.h"
#include "DawgHops.h"
#include "card.h"
#include <fstream>

/*
void phaseOne()
{
    // Default Constructor Test
    Node n1;

    std::cout << "Value: " << n1.getValue() << std::endl;

    n1.setValue(10);
    std::cout << "Value: " << n1.getValue() << std::endl;

    Node n2;
    n2.setValue(15);
    std::cout << "Value: " << n2.getValue() << std::endl;
    //no leaks
	
	

}

void phaseTwo()
{
    LinkedList * myList = new LinkedList();
    LinkedNode * ptr1 =  new LinkedNode (5);
    LinkedNode * ptr2 =  new LinkedNode (15);

    myList->insert(10);
    myList->insert(45);
    myList->insert(95);

    myList->printList();
	
    myList->getLength();
    std::cout << std::endl;

    myList->isEmpty();

    std::cout << "Inserting head..." << std::endl;
    myList->setHead(ptr2);
    myList->printList();
    myList->getLength();
    std::cout << std::endl;

    std::cout << "Inserting tail..." << std::endl;
    myList->setTail(ptr1);
    myList->printList();
    myList->getLength();
    std::cout << std::endl;

    std::cout << "head = "<< myList->getHead()->getValue() << std::endl;
    std::cout << "tail = "<< myList->getTail()->getValue() << std::endl;
	

    delete myList;
}

void phaseThree()
{

    // no test for phase three

}
void phaseFour()
{
	DoublyLinkedList * myList = new DoublyLinkedList();
	
	myList->insertLinkedNode(myList->getTail(), 15);
	myList->insertLinkedNode(myList->getTail(), 10);
	myList->insertLinkedNode(myList->getTail(), 20);
	myList->insertLinkedNode(myList->getTail(), 17);
	
	myList->printList();
	
	delete myList;
}
*/
void phaseFive()
{
	DoublyLinkedList * myList = new DoublyLinkedList();
	
	dawgHops * hops;
	
	std::ifstream in("testdeck.txt");
	
	if(in.is_open())
	{
		int size;
		in >> size;
		
		int suit, face;
		for(int i = 0; i < size; i++)
		{
			in >> suit >> face;
			Card c(suit, face);
			myList->insert(c);
		}
	}
	
	in.close();
	myList->printList();
	std::cout << std::endl;
	
	int temp = 0;
	
	hops->insertionSort(myList, temp);
	
	std::cout << "Insertion Sort... " << std::endl;
	std::cout << std::endl;
	myList->printList();
	std::cout << std::endl;
	std::cout << "Dawg Hops: " << temp << std::endl;
	std::cout << std::endl;
	
	delete myList;
	
	
}

int main()
{

    // phaseOne();
   // phaseTwo();
    // phaseThree();
    //phaseFour();
   phaseFive();

   

    return 0;
}
