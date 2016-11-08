/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/10/26
Description: This function takes an input character array and encrypts
             it using ROT3 encryption.
*/

#include "lab10_header.h"

void getInput(char encryptArray[])
{
  cout << "Please enter the string you would like to encrypt: " << endl;
  cin.getline(encryptArray, CHAR_LENGTH);

  return;
}

void encrypt(char encryptArray[])
{
  for(int i = 0; i < CHAR_LENGTH; i++)
  {
    if(encryptArray[i] == '\0')
    {
      break;
    }
    if(islower(encryptArray[i]))
    {
      encryptArray[i] = (encryptArray[i] - 'a' + 3);
      encryptArray[i] = encryptArray[i] % 26;
      encryptArray[i] += 'a';
    }
    else if(isupper(encryptArray[i]))
    {
      encryptArray[i] = (encryptArray[i] - 'A' + 3);
      encryptArray[i] = encryptArray[i] % 26;
      encryptArray[i] += 'A';
    }
  }
  return;
}

void showOutput(char encryptArray[])
{
  cout << endl << "Your encrypted string is: ";
  for(int i=0;i<CHAR_LENGTH;i++)
  {
    if (encryptArray[i] != '\0')
    {
      cout << encryptArray[i];
    }
    else
    {
      break;
    }
  }

  cout << endl << endl << "Thank you, goodbye!" << endl;
  return;
}
