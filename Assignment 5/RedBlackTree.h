/* 
CS 341 - Assignment 5
Date: 11/5/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree
{
	public:
		RedBlackTree();
		~RedBlackTree();
		
		virtual void insert(int data);
		
		void printRedNodes(TreeNode * node);
		void printBlackNodes(TreeNode * node);
		
	private:
		void rotateLeft(TreeNode *& root, TreeNode *& newNode);
		void rotateRight(TreeNode *& root, TreeNode *& newNode);
		void balanceColor(TreeNode *& root, TreeNode *& newNode);
	
	
	
	
};

#endif