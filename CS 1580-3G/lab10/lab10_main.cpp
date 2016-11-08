/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/10/26
Description: This function takes an input character array and encrypts
             it using ROT3 encryption.
*/


#include "lab10_header.h"

int main()
{
  /////////
  // initializing character array for user input
  /////////
  char encryptArray[CHAR_LENGTH];

  /////////
  // Receiving user input
  /////////
  getInput(encryptArray);

  /////////
  // Encrypt computation on the array.
  /////////
  encrypt(encryptArray);

  /////////
  // Printing output of encryptArray after encrypting
  /////////
  showOutput(encryptArray);

  /////////
  // Adios
  /////////
  return 0;
}
