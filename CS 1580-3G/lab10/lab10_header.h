/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/10/26
Description: This function takes an input character array and encrypts
             it using ROT3 encryption.
*/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int CHAR_LENGTH = 80;

//////////
// @Pre: Name must initialized to an array that is greater in size than
//       the input
// @Post: Name will be given values between the index 0 and n where n
//        is number of characters the users entered minus one
// @Description: This function get the input from the user and enters it
//               into a null terminated character array.
//////////
void getInput(char name[]);

//////////
// @Pre: Name must be alphabetic ASCII characters or encrypt will not
//       ROT3 properly. The null terminated character must be at index less
//       than CHAR_LENGTH - 1.
// @Post: The character array will be ROT3 ignoring spaces.
// @Description: This function rotates the alphabetic ASCII characters
//               by three.
//////////
void encrypt(char name[]);

//////////
// @Pre: The null terminated character must be at index less
//       than CHAR_LENGTH - 1
// @Post: The encrypted character array is printed to the screen.
// @Description: This funciton prints the encrypted character array to
//               the screen.
//////////
void showOutput(char name[]);


#endif
