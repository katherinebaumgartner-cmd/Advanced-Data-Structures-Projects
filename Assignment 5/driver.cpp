/* 
CS 341 - Assignment 5
Date: 11/5/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include <fstream>
#include <iostream>

#include "BinarySearchTree.h"
#include "TreeNode.h"
#include "Node.h"
#include "RedBlackTree.h"

void phaseOne()
{
	std::ifstream in("data.txt");
	
	if(in.is_open())
	{	
		int data;
		while(!in.eof())
		{
			in >> data;
			std::cout << data << " ";
		}
		std::cout << std::endl;
	}
	
	in.close();
}

void phaseTwo()
{
	std::ifstream in("data.txt");
	
	BinarySearchTree * myTree = new BinarySearchTree;
	
	if(in.is_open())
	{	
		int data;
		while(!in.eof())
		{
			in >> data;
			//std::cout << data << " ";
			myTree->insert(data);
		}
		std::cout << std::endl;
	}
	
	in.close();
	
   // myTree->print();
	
	std::cout << "Root: ";
	std::cout << myTree->getRoot()->getValue() << std::endl;
	std::cout << " " << std::endl;
	
	//std::cout << "Height: " << myTree->getHeight(myTree->getRoot()) << std::endl;
	
	delete myTree;

}

void phaseThree()
{
	std::ifstream in("data.txt");
	
	RedBlackTree * myTree = new RedBlackTree;
	
	if(in.is_open())
	{	
		int data;
		while(!in.eof())
		{
			in >> data;
			//std::cout << data << " ";
			myTree->insert(data);
		}
		std::cout << std::endl;
	}
	
	in.close();
	
   // myTree->print();
    std::cout<< "Root: " << myTree->getRoot()->getValue() << std::endl;
	std::cout << std::endl;
	
	myTree->getRoot()->printColor();
	std::cout << std::endl;
	
	delete myTree;
	
}

void phaseFour()
{
	std::ifstream in("data.txt");
	
	RedBlackTree * myTree = new RedBlackTree;
	
	if(in.is_open())
	{	
		int data;
		while(!in.eof())
		{
			in >> data;
			//std::cout << data << " ";
			myTree->insert(data);
		}
		std::cout << std::endl;
	}
	
	in.close();
	
	//myTree->print();
	
	std::cout << "Root: ";
	std::cout << myTree->getRoot()->getValue() << std::endl;
	std::cout << " " << std::endl;
	
	delete myTree;
	
}

void phaseFive()
{
	std::ifstream in("data.txt");
	
	RedBlackTree * myTree = new RedBlackTree;
	
	if(in.is_open())
	{	
		int data;
		while(!in.eof())
		{
			in >> data;
			//std::cout << data << " ";
			myTree->insert(data);
		}
		std::cout << std::endl;
	}
	
	in.close();
	
	//myTree->print();
	
	std::cout << "Red: ";
	myTree->printRedNodes(myTree->getRoot());
	std::cout << std::endl;
	
	std::cout << "Black: ";
	myTree->printBlackNodes(myTree->getRoot());
	std::cout << std::endl;
	
	std::cout << "Root: ";
	std::cout << myTree->getRoot()->getValue() << std::endl;
	std::cout << " " << std::endl;
	
	std::cout << "Height: " << myTree->getHeight(myTree->getRoot()) << std::endl;
	
	delete myTree;
}

int main()
{

    // phaseOne();
 //  phaseTwo();
   // phaseThree();
   // phaseFour();
	phaseFive();

    return 0;
}