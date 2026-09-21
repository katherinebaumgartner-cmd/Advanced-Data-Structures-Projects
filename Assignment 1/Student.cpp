// CS 341 - Assignment 1
//
// Date: 9/4/25
//
// Honor Pledge: I pledge that I have neither given nor received any help on this assignment.
//
// By: Katie Baumgartner

//cpp is where you do all the actions and use the stuff in header file

// Source/Implementation File

// Links the implementation to the declaration.
#include "Student.h" // Should only ever have one (1) include here!

// Class :: <scope resolution operator> Constructor/Destructor/Method/Attribute

//put methods/functions in here after declaring them in header file

//function in my class

Student::Student() //default constructor
{
}

Student::Student(std::string id, int gradePoints, int creditHours) //constructor
{
	id_ = id;
	gradePoints_ = gradePoints;
	creditHours_ = creditHours;
	GPs_ = (double)gradePoints_/creditHours_;
	
	//Letter grade
	if(GPs_ >= 3.70)
	{
		LG_ = 'A';
	}
	else if(GPs_ >= 2.70)
	{
		LG_ = 'B';
	}
	else if(GPs_ >= 1.70)
	{
		LG_ = 'C';
	}
	else if(GPs_ >= 0.70)
	{
		LG_ = 'D';
	}
	else
	{
		LG_ = 'F';
	}
		
}

Student::~Student() //destructor
{
	// Empty
}

//Getters
std::string Student::getID()
{
	return id_;
}
int Student::getGradePoints()
{
	return gradePoints_;
}
int Student::getCreditHours()
{
	return creditHours_;
}
double Student::getGPs()
{
	return GPs_;
}
char Student::getLG_()
{
	return LG_;
}

//Setters
void Student::setID(std::string id)
{
	id_ = id;
}
void Student::setGradePoints(int gradePoints)
{
	gradePoints_ = gradePoints;
}
void Student::setCreditHours(int creditHours)
{
	creditHours_ = creditHours;
}
