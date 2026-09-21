
# CS 341 - Assignment 6
# Date: 12/12/2025
# Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
# By: Katie Baumgartner and David Jefferson


HASH.exe: driver.o HashEntry.o HashTable.o HashTableArray.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o HashTableChaining.o HashTableCuckoo.o
	g++ driver.o HashEntry.o HashTable.o HashTableArray.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o HashTableChaining.o HashTableCuckoo.o -o HASH.exe
	
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

HashEntry.o: HashEntry.cpp
	g++ -c HashEntry.cpp -o HashEntry.o
	
HashTable.o: HashTable.cpp
	g++ -c HashTable.cpp -o HashTable.o
	
HashTableArray.o: HashTableArray.cpp
	g++ -c HashTableArray.cpp -o HashTableArray.o
	
Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o
	
LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o
	
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o
	
DoublyLinkedList.o: DoublyLinkedList.cpp
	g++ -c DoublyLinkedList.cpp -o DoublyLinkedList.o
	
HashTableChaining.o : HashTableChaining.cpp
	g++ -c HashTableChaining.cpp -o HashTableChaining.o
	
HashTableCuckoo.o : HashTableCuckoo.cpp
	g++ -c HashTableCuckoo.cpp -o HashTableCuckoo.o
	
run:
	HASH.exe
	
clean:
	rm -f *.o *.exe 
	# Inference Rules (*)
	
# Target: Dependency List
# <TAB>Shell Line(s)
# 
# Both Lines == Rule