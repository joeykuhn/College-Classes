#ifndef SWAP_H
#define SWAP_H
/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/10/05
Description: This program takes two integer inputs from the user,
             swaps both of the values by reference, and then
	     prints the results.
*/

#include <iostream>
using namespace std;

//////////
// @Pre: Both Value One and Value Two must exsist.
// @Post: Values One and Value Two will be switched by reference
// @Function: This function takes the Value One and Value two and
//            swaps their value by reference.
//////////
void swapFunction(int &value1, int &value2);

#endif
