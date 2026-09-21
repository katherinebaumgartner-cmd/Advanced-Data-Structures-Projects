/* 
CS 341 - Assignment 5
Date: 11/5/25
Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
By: Katie Baumgartner and David Jefferson
*/

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	root_ = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	if(root_ != nullptr)
	{
		delete root_;
	}
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree & tree) : root_(nullptr), height_(0)
{
	root_ = copyTree(tree.root_); //copy root and recursion will do the rest	
}

void BinarySearchTree::insert(int data)
{
	TreeNode * newNode = new TreeNode(data);
	
	root_ = insertNode(root_, newNode);
	
	//phase 3 in-class code
	
	//balanceColor(root_); //allow us to balance the tree once we have inserted a node
	
	//root->setColor(BLACK); //Sets root of the overall tree to black, last step that you want to do
}

TreeNode * BinarySearchTree::insertNode(TreeNode * root, TreeNode * node)
{
    //step 1 empty tree insert 
    if(root == nullptr) //power of recursion, use root of subtree
    {
        return node;
    }
    else
    {
        if(node->getValue() > root->getValue()) //right subtree
        {
			//recursively going through until it finds a place for the node
            root->setRightChild(insertNode(root->getRightChild(),node)); //forward link
            root->getRightChild()->setParent(root); //backward link
        }
        else //left subtree
        {
            root->setLeftChild(insertNode(root->getLeftChild(),node)); //forward link
            root->getLeftChild()->setParent(root); //backward link

        }
        return root;
    }
}
/*
//written in class
void BinarySearchTree::deleteNode(int data);
{
	root_ = deleteTreeNode(root_, data);
}
*/
/*
//written in class
TreeNode * BinarySearchTree::deleteTreeNode(TreeNode * root, int data)
{
	if(root == nullptr)
	{
		return nullptr;
	}
	
	if(data < root->getValue())
	{
		//left subtree
		root->setLeftChild(deleteTreeNode(root->getLeftChild(), data)); //go until you reach the nullptr
	}
	else if(data > root->getValue())
	{
		//right subtree
		root->setRightChild(deleteTreeNode(root->getRightChild(), data)); //go until you reach the nullptr
	}
	else
	{
		if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr)
		{
			//leaf node
			delete root;
			
			return nullptr;			
		}
		else if(root->getLeftChild() == nullptr) //flip flops the two nodes
		{
			//right child only
			TreeNode * node = root->getRightChild();
			
			root->setValue(node->getValue());
			root->setLeftChild(node->getLeftChild());
			root->setRightChild(node->getRightChild());
			
			node->setLeftChild(nullptr);
			node->setRightChild(nullptr);
			node->setParent(nullptr);
			
			delete node;
			
			return root;
		}
		else if(root->getRightChild() == nullptr)
		{
			//left child only
			TreeNode * node = root->getRightChild();
			
			root->setValue(node->getValue());
			root->setLeftChild(node->getLeftChild());
			root->setRightChild(node->getRightChild());
			
			node->setLeftChild(nullptr);
			node->setRightChild(nullptr);
			node->setParent(nullptr);
			
			delete node;
			
			return root;
		}	
		else
		{
			//node with two children...
			TreeNode * node = root->getRightChild();
			
			while(node != nullptr && node->getLeftChild() != nullptr) // find location in the tree where i need to go to
			{
				node = node->getLeftChild(); //go until we get the leftmost child of the right subtree				
			}
			
			root->setValue(node->getValue());
			
			root->setRightChild(deleteTreeNode(root->getRightChild(), node->getValue); 
		}
	}	
	
	return root;
}
*/

int BinarySearchTree::getHeight(TreeNode * node)
{
	int leftHeight(0), rightHeight(0), height(0);
	
	if(node == nullptr)
	{
		return height;
	}
	else
	{
		leftHeight = getHeight(node->getLeftChild());
		rightHeight = getHeight(node->getRightChild());
		
		if(leftHeight > rightHeight)
		{
			height = leftHeight;
		}
		else
		{
			height = rightHeight;
		}
		
		return height + 1;
	}
}

void BinarySearchTree::print()
{
	std::cout << "Inorder Traversal: ";
	inorder(root_);
	std::cout << std::endl << "Preorder Traversal: ";
	preorder(root_);
	std::cout << std::endl << "Postorder Traversal: ";
	postorder(root_);
	std::cout << std::endl;
}

void BinarySearchTree::inorder(TreeNode * node)
{
    if(node == nullptr)//if it is empty (Base Case)
    {
        return;
    }
    inorder(node->getLeftChild());
    std::cout<< node->getValue() << " ";
    inorder(node->getRightChild());
} 
void BinarySearchTree::preorder(TreeNode * node)
{
    if(node == nullptr)//if it is empty (Base Case)
    {
        return;
    }
    std::cout<< node->getValue() << " "; //print root
    preorder(node->getLeftChild());
    preorder(node->getRightChild());
} 
void BinarySearchTree::postorder(TreeNode * node)
{
    if(node == nullptr)//if it is empty (Base Case)
    {
        return;
    }
    postorder(node->getLeftChild());
    postorder(node->getRightChild());
    std::cout<< node->getValue() << " "; //print root
} 


void BinarySearchTree::setRoot(TreeNode * root)
{
	root_ = root;
}

TreeNode * BinarySearchTree::getRoot()
{
    return root_;
}

TreeNode * BinarySearchTree::copyTree(TreeNode * node)
{
	if(node == nullptr)
	{
		return nullptr;
	}
	else
	{
		TreeNode * newNode = new TreeNode(node->getValue());
		
		newNode->setLeftChild(copyTree(node->getLeftChild()));
		newNode->setRightChild(copyTree(node->getRightChild()));
		return newNode;		
	}
	
}