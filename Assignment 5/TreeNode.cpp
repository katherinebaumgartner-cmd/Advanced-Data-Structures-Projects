/* 
CS 341 - Assignment 5
Date: 11/5/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "TreeNode.h"

TreeNode::TreeNode() : TreeNode (0)
{
	
}

TreeNode::TreeNode(int data) : Node(data), leftChild_(nullptr), rightChild_(nullptr), parent_(nullptr), color_(false)
{
	
}

TreeNode::~TreeNode()
{
	if(leftChild_ != nullptr)
	{
		delete leftChild_;
	}
	if(rightChild_ != nullptr)
	{
		delete rightChild_;
	}
}

void TreeNode::setLeftChild(TreeNode * leftChild)
{
	leftChild_ = leftChild;
}

void TreeNode::setRightChild(TreeNode * rightChild)
{
	rightChild_ = rightChild;
}

void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}

TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}

TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}

TreeNode * TreeNode::getParent()
{
	return parent_;
}

void TreeNode::setColor(bool c) //true = black, false = red
{
	color_ = c;
}

bool TreeNode::getColor()
{
	return color_;
}

void TreeNode::printColor()
{
	if(getColor())
	{
		std::cout << "Color: Black" << std::endl;
	}
	else
	{
		std::cout << "Color: Red" << std::endl;
	}	
}