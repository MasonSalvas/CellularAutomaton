// Cellular.cpp : Defines the entry point for the console application.
/*
Mason Salvas
November 12, 2012

Assignment Cellular
This program will output a design based on the formula
*/


#include <iostream>

using namespace std;

int getInput();						//function that gets the input data
void automaton(bool current[]);		//the math for squares
void display(bool current[]);		//the output or display


int main()
{//Begin Main

	bool current[80];
	int var;

	var = getInput();

	for (int q = 0; q < var; q++)
	{
		automaton(current);							//will loop everytime for however many rows the user inputed
		display(current);
	}

	cin.get();
	cin.get();
	return 0;
}//End Main

int getInput()										//allows the user to input the number of rows in the output
{
	int numLines;

	cout << "How many lines do you want: ";
	cin >> numLines;									//enter the number of lines that the user wants to see

	while ((numLines < 1) || (numLines > 99))
	{
		cout << "How many lines do you want: ";
		cin >> numLines;							//input validation
	}

	return numLines;

}

void automaton(bool current[])					//The math behind the 
{
	bool prev[80];


	for (int i = 0; i < 80; i++)
		prev[i] = current[i];					//switches the current array and puts it as the old array			

	for (int j = 0; j < 80; j++)
	{
		bool upLeft, up;

		if (j > 0)
			upLeft = prev[j - 1];				//the up left is one less than the one directly above the current position						
		else
			upLeft = false;

		up = prev[j];							//the one above the array is directly above it

		current[j] = (upLeft != up);			//current would be true if the up left and the up are not equal to each other
	}
}

void display(bool current[])
{
	char square = 254;
	char space = ' ';

	for (int c = 0; c < 80; c++)
	{
		if (current[c])					//if current is true then it will print out a square 
			cout << square;
		else
			cout << space;			//else it will print a space
	}

}