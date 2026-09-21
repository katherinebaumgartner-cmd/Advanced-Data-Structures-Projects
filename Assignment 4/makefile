# CS 341 - Assignment 4
#
# Date: 10/22/25
#
# Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
#
# By: Katie Baumgartner and David Jefferson

BIT.exe: Driver.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o card.o DawgHops.o
	g++ Driver.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o card.o DawgHops.o -o LinkedList.exe

Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o
	
Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o
	
LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o
	
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o
	
DoublyLinkedList.o: DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp -o DoublyLinkedList.o
	
card.o: card.cpp
	g++ -c card.cpp -o card.o

DawgHops.o: DawgHops.cpp
	g++ -c DawgHops.cpp -o DawgHops.o
	
run:
	LinkedList.exe
	
clean:
	rm -f *.o *.exe 
	# Inference Rules (*)
	
# Target: Dependency List
# <TAB>Shell Line(s)
# 
# Both Lines == Rule