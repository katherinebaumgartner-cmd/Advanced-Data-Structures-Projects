/* 
CS 341 - Assignment 5
Date: 11/5/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"

class BinarySearchTree
{
	public:
		BinarySearchTree();
		virtual ~BinarySearchTree();
		BinarySearchTree(const BinarySearchTree & tree);
		
		virtual void insert(int data);
		//void deleteNode(int data); //written in class
		void print();
		TreeNode * getRoot();
		void clear(TreeNode* node);
		void setRoot(TreeNode * root);
		
		int getHeight(TreeNode * node);
		
	protected:
		TreeNode * insertNode(TreeNode * root, TreeNode * node);
		TreeNode * deleteTreeNode(TreeNode * root, int data);
		//void setRoot(TreeNode * root);
		void inorder(TreeNode * node);
		void preorder(TreeNode * node);
		void postorder(TreeNode * node);
		TreeNode * root_;	
		int height_;
		
	private:
		TreeNode * copyTree(TreeNode * node);
		
};

#endif