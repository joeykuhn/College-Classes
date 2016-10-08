/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/10/05
Description: This program takes two integer inputs from the user,
             swaps both of the values by reference, and then
	     prints the results.
*/
#include "header_swap.h"

int main()
{
  //////////
  // Variable initialization for user inputs
  //////////
  int numberOne = 0;
  int numberTwo = 0;

  //////////
  // Formatting for initial user input and user input for numberOne
  //////////
  cout << "Enter the value for the first swap number: ";
  cin >> numberOne;

  //////////
  // Formatting for secondary user input and user input for numberTwo
  //////////
  cout << "Enter the value for second swap number: ";
  cin >> numberTwo;

  //////////
  // Formatting for output and output of number before the swap
  //////////
  cout << "Before swapping, the value of Swap Number One: " << numberOne
       << " the value of Swap Number Two: " << numberTwo << endl;

  //////////
  // The actual swapping of numbers
  //////////
  swapFunction(numberOne, numberTwo);

  //////////
  // Output
  //////////
  cout << "After swapping, the value of Swap Number One: " << numberOne
       << " the value of Swap Number Two: " << numberTwo << endl;

  //////////
  // Obligatory End
  //////////
  return 0;
}


