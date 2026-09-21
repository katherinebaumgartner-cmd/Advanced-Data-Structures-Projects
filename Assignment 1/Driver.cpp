// CS 341 - Assignment 1
//
// Date: 9/4/25
//
// Honor Pledge: I pledge that I have neither given nor received any help on this assignment.
//
// By: Katie Baumgartner

#include <iostream> 
#include <fstream> 
#include "Student.h" 
#define SIZE 30


// everytime you want to input/output anything you use sd: : becuase there is no namespace

void bubbleSort(Student crap[], int n)
{
	int i;
	int j;
	
	//bubble sort
	for (i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			//rearranging based on the GPA size
			if (crap[j].getGPs() < crap[j + 1].getGPs())
			{
				Student temp = crap[j];
				crap[j] = crap[j + 1];
				crap[j + 1] = temp;
			}
		}
	}
}

void printArray(Student crap[], int n)
{
	int i;
	
	//printing
	for (int i = 0; i < n; i++) 
	{
		std::cout << crap[i].getID() << ": " << std::fixed << std::setprecision(2) << crap[i].getGPs() << " " << crap[i].getLG_() << std::endl;
    }
}

int main()
{
	//opens file
    std::ifstream inputFile("students.txt"); 
	
	//Declaring variables
	int GPs, CHs;
	std::string idn;
	Student crap[SIZE];
	int i = 0;
	int n = 0;
	int listSize;
	
	std::cout << "**** Welcome to the GPA Calculator Program! ****" << std::endl;
	
	//doing this while there is still a line to get
    while(inputFile >> idn >> GPs >> CHs) 
	{
		//reading file and assigning it to the array
		crap[i] = Student(idn, GPs, CHs);
		//adding 1 to i so the array keeps making a new thing
		i++;		
    }
	
	//Finding the size of the array
	n = sizeof(crap)/sizeof(crap[0]);
	
	//Sorting function call
	bubbleSort(crap, n);
	
	//Printed out the sorted array
	printArray(crap, n);

	std::cout << "Thank you for using the GPA calculator program - goodbye!" << std::endl;

	//closes file
    inputFile.close();

    return 0;
}

