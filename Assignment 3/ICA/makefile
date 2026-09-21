// CS 341 - Assignment 3
//
// Date: 10/3/25
//
// Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
//
// By: Katie Baumgartner and David Jefferson

BIT.exe: ICA 10-8.o bitarray.o
	g++ driver.o bitarray.o -o BIT.exe

ICA 10-8.o: ICA 10-8.cpp
	g++ -c ICA 10-8.cpp -o ICA 10-8.o
	
bitarray.o: bitarray.cpp
	g++ -c bitarray.cpp -o bitarray.o
	
run:
	BIT.exe
	
clean:
	rm -f *.o *.exe 
	# Inference Rules (*)
	
# Target: Dependency List
# <TAB>Shell Line(s)
# 
# Both Lines == Rule