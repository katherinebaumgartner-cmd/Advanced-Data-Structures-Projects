/* 
CS 341 - Assignment 5
Date: 11/5/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef TREENODE_H
#define TREENODE_H

#include "Node.h"
#include <iostream>

class TreeNode : public Node
{
	public:
		TreeNode();
		TreeNode(int data);
		~TreeNode();
		void setLeftChild(TreeNode * leftChild);
		void setRightChild(TreeNode * rightChild);
		void setParent(TreeNode * parent);
		TreeNode * getLeftChild();
		TreeNode * getRightChild();
		TreeNode * getParent();
		
		void setColor(bool c);
		bool getColor();
		void printColor();
		
	private:
		TreeNode * leftChild_;
		TreeNode * rightChild_;
		TreeNode * parent_;
		bool color_;

};

#endif