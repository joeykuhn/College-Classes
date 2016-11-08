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

void swapFunction(int &valueOne, int &valueTwo)
{
  int temp = 0;

  temp = valueOne;
  valueOne = valueTwo;
  valueTwo = temp;

  return;
}
