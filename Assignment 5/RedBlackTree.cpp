/* 
CS 341 - Assignment 5
Date: 11/5/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "RedBlackTree.h"

RedBlackTree::RedBlackTree()
{
	
}

RedBlackTree::~RedBlackTree()
{
	
}

void RedBlackTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	
	TreeNode * root = nullptr;
	
	root_ = insertNode(root_, newNode);
	
	if((root_->getColor()) != true)
	{
		root_->setColor(true);
	}
	
	balanceColor(root, newNode);
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode * rightChild = newNode->getRightChild();
    newNode->setRightChild(rightChild->getLeftChild());

    newNode->setRightChild(rightChild->getLeftChild());

    if(newNode->getRightChild() != nullptr)
    {
        newNode->getRightChild()->setParent(newNode);
    }
    rightChild->setParent(newNode->getParent());

    if(newNode->getParent() == nullptr) //newNode is root
    {
        BinarySearchTree::setRoot(rightChild); //update root
    }
    else if(newNode == newNode->getParent()->getRightChild()) //left child
    {
        newNode->getParent()->setRightChild(rightChild);
    }
    else //right child
    {
        newNode->getParent()->setLeftChild(rightChild);
    }
    rightChild->setLeftChild(newNode); //put newNode on right of leftChild
    newNode->setParent(rightChild); //update parent of newNode	
}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode * leftChild = newNode->getLeftChild();
    newNode->setLeftChild(leftChild->getRightChild());

    newNode->setLeftChild(leftChild->getRightChild());

    if(newNode->getLeftChild() != nullptr)
    {
        newNode->getLeftChild()->setParent(newNode);
    }
	
    leftChild->setParent(newNode->getParent());

    if(newNode->getParent() == nullptr) //newNode is root
    {
        root = leftChild; //update root
		BinarySearchTree::setRoot(leftChild);
    }
    else if(newNode == newNode->getParent()->getLeftChild()) //left child
    {
        newNode->getParent()->setLeftChild(leftChild);
    }
    else //right child
    {
        newNode->getParent()->setRightChild(leftChild);
    }
	
    leftChild->setRightChild(newNode); //put newNode on right of leftChild
    newNode->setParent(leftChild); //update parent of newNode

}

//root is the parent of newNode in this instance
void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode * parent = nullptr;
	TreeNode * grandParent = nullptr;
	
	while((newNode != root_) && (newNode->getColor() != true) && (newNode->getParent()->getColor() == false))
	{		
		parent = newNode->getParent();
		grandParent = parent->getParent();
		
		if(grandParent == nullptr)
		{
			parent->setColor(true);				
		}
		//parent is left child
		else if(parent == grandParent->getLeftChild())
		{
			TreeNode * aunt = grandParent->getRightChild();
			 
			 // checks to see if it has a red aunt
			 if((aunt != nullptr) && (aunt->getColor() == false))
			 {
				 //true = black, false = red
				 aunt->setColor(true);
				 parent->setColor(true);
				 grandParent->setColor(false);
				 
				 newNode = grandParent;
			 }
			 //no aunt
			 else
			 {
				 //newNode is the rightChild
				 if(newNode == parent->getRightChild())
				 {
					 rotateLeft(root, parent);
					 
					 newNode = parent;
					 parent = newNode->getParent();
				 }
				 //newNode is the leftChild
				 else
				 {
					 rotateRight(root, grandParent);
					 
					 parent->setColor(true);
					 grandParent->setColor(false);
					 
					 newNode = parent;
				 }
			 }
		 }
		// parent is right child
		else
		{
			 TreeNode * aunt = grandParent->getLeftChild();
			 
			 // has red aunt
			 if((aunt != nullptr) && (aunt->getColor() == false))
			 {
				 //true = black, false = red
				 aunt->setColor(true);
				 parent->setColor(true);
				 grandParent->setColor(false);
				 
				 newNode = grandParent;
			 }
			 
			 // has no aunt or aunt is black
			 else
			 {
				 // newNode is left child
				 if(newNode == parent->getLeftChild())
				 {
					 //rotating newNode and parent (newNode becomes parent)
					 rotateRight(root, parent);
					 					 
					 newNode = parent;
					 parent = newNode->getParent();

				 }
				 //newNode is right child
				 else
				 {
					 rotateLeft(parent, grandParent);
					 
					 parent->setColor(true);
					 grandParent->setColor(false);
					 
					 newNode = parent;
				 }
			 }
		 }
	}
	root_->setColor(true);
}

void RedBlackTree::printRedNodes(TreeNode * node)
{
	if(node == nullptr)//if it is empty (Base Case)
    {
        return;
    }
    printRedNodes(node->getLeftChild());
	
	if(!node->getColor())
	{
		std::cout << node->getValue() << " ";
	}
	
    printRedNodes(node->getRightChild());

}

void RedBlackTree::printBlackNodes(TreeNode * node)
{
	if(node == nullptr)//if it is empty (Base Case)
    {
        return;
    }
	
	if(node->getColor())
	{
		std::cout << node->getValue() << " ";
	}
	
    printBlackNodes(node->getLeftChild());
    printBlackNodes(node->getRightChild());
}