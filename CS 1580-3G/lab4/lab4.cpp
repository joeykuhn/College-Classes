/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 16/14/09
Description: This program displays to the users a list of things, askes them which they value the most, and then places them into the correct Hogwarts house depending on the answer.
*/
#include <iostream>
using namespace std;


int main()
{
  //Variable Initialization
  std::string name;
  short importanceNumber = 0; 
  
  //Initial formatting for user
  cout << "Hello, please enter your name: ";
  cin >> name;
  cout << "It is fantastic to meet you " << name << " Let us begin!" << endl
       << " Please choose which you value most: " << endl
       << "=====================================" << endl
       << "= 1) Courage                        =" << endl
       << "= 2) Intelligence                   =" << endl
       << "= 3) Hard Work                      =" << endl
       << "= 4) Ambition                       =" << endl
       << "=====================================" << endl
       << endl;
  
  //User input and answer output
  do
  {
    cout << " Please enter your value (1-4) here: ";
    cin >> importanceNumber;

    if(importanceNumber == 1)
    {
      cout << name <<", You will be a Gryffindor. Goodbye." << endl;
    }
    else if(importanceNumber == 2)
    {
      cout << name <<", You will be a Ravenclaw. Goodbye." << endl;
    }
    else if(importanceNumber == 3)
    {
      cout << name << ", You will be a Hufflepuff. Goodbye." << endl;
    }
    else if(importanceNumber == 4)
    {
      cout << name << ", You will be a Slytherin. Goodbye." << endl;
    }
  } 
  while(importanceNumber <= 0 or importanceNumber > 4);

  //Obligatory End
  return 0;
}
