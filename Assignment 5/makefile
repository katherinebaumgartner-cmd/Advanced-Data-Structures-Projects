#
# CS 341 - Assignment 5
# Date: 11/5/25
# Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
# By: Katie Baumgartner and David Jefferson
#

BST.exe: driver.o BinarySearchTree.o TreeNode.o Node.o RedBlackTree.o
	g++ driver.o BinarySearchTree.o TreeNode.o Node.o RedBlackTree.o -o BST.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp -o BinarySearchTree.o
	
TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o
	
Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o
	
RedBlackTree.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RedBlackTree.o
	
	
run:
	BST.exe
	
clean:
	rm -f *.o *.exe 
	# Inference Rules (*)
	
# Target: Dependency List
# <TAB>Shell Line(s)
# 
# Both Lines == Rule