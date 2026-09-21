// CS 341 - Assignment 1
//
// Date: 9/4/25
//
// Honor Pledge: I pledge that I have neither given nor received any help on this assignment.
//
// By: Katie Baumgartner

//header file is list of all the fucnctions in your class
#include <string>
#include <iostream>
#include <iomanip>


class Student
{ 
	private:
		std::string id_;
		int gradePoints_, creditHours_;
		double GPs_;
		int n;
		char LG_;
	
	public:
	
		Student(); //Default constructor
		Student(std::string id, int gradePoints, int creditHours); // coonstructor
		~Student(); //destructor
		
		//getters
		std::string getID();
		int getGradePoints();
		int getCreditHours();
		double getGPs();
		char getLG_();
		
		//setters
		void setID(std::string id);
		void setGradePoints(int gradePoints);
		void setCreditHours(int creditHours);
		

};