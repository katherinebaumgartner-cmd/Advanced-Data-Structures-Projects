# CS 341 - Assignment 3
#
# Date: 10/3/25
#
# Honor Pledge: I pledge that I have neither given nor received any help on this assignment except for David Jefferson
#
# By: Katie Baumgartner and David Jefferson

BIT.exe: driver.o bitarray.o set.o dictionary.o
	g++ driver.o bitarray.o set.o dictionary.o -o BIT.exe

Driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o
	
bitarray.o: bitarray.cpp
	g++ -c bitarray.cpp -o bitarray.o
	
set.o: set.cpp
	g++ -c set.cpp -o set.o
	
dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp -o dictionary.o
	
run:
	BIT.exe
	
clean:
	rm -f *.o *.exe 
	# Inference Rules (*)
	
# Target: Dependency List
# <TAB>Shell Line(s)
# 
# Both Lines == Rule