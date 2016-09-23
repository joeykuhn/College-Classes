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

  std::string houses[] = {"Gryffindor","Ravenclaw","Hufflepuff","Slytherin"};
 
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

  cout << "Please input your answer here: ";
  cin >> importanceNumber;
 
switch(importanceNumber)
 case 1: 



  return 0;
}
