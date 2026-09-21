# CS 341 - Assignment 1
#
# Date: 9/4/25
#
# Honor Pledge: I pledge that I have neither given nor received any help on this assignment.
#
# By: Katie Baumgartner
#
# Note: If your makefile has an extension and/or isn't named makefile then you need to type the following:
# 		make -f NAME_OF_MAKEFILE.EXTENSION OF MAKEFILE (e.g., make -f makefile.txt)

GPA.exe: Driver.o Student.o
	g++ Driver.o Student.o -o GPA.exe

Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o
	
Student.o: Student.cpp
	g++ -c Student.cpp -o Student.o
	
run:
	GPA.exe
	
clean:
	rm -f *.o *.exe *.txt 
	# Inference Rules (*)
	
# Target: Dependency List
# <TAB>Shell Line(s)
# 
# Both Lines == Rule