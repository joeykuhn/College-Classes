/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/09/28
Description: This program analyzes a user input, validates
             the input in order to make sure it is positive,
	     and then checks if the input is even or odd.
*/
#include <iostream>
using namespace std;

//////////
// Initialization of variables which are contingent upon
// the users input.
//////////
int userInput = 0; //Actual user input
int userOutput = 0; //User input handler for function calls


//////////
// Function Prototypes
//////////

//Description: Greeting message is output to the screen
//Pre: None
//Post: Greeting message is output to the screen
void greet();

//Description: Read a user input for number and make sure it is positive
//           : if it is negative, keep asking until it is positive
//Pre  : None
//Post : A non-negative number is returned
int readNumber();


//Description: Identify and return the divisbility of the number
//Pre: the parameter number must be positive
//Post: Divisbility of the number is returned
bool isEven(int number);

//Description: The number and the result are output on the screen
//Pre: None
//Post: The number and the result are output on the screen
void printResult(int number, bool result);

//Description: A signoff message is output on the screen
//Pre: None
//Post: A signoff message is output on the screen
void signoff();



//////////
// Helper functions
/////////
void greet()
{
  cout << "Welcome to the ODD-EVEN Analyzer" << endl;
  return;
}

int readNumber()
{
  int userInput = 0;
  do{
  cout << "Please enter a positive number: ";
  cin >> userInput;
  }
  while(userInput <= 0);

  return userInput;
}

bool isEven( int inputNumber )
{
  if(inputNumber % 2 == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void printResult( int number, bool result)
{
  cout << endl 
       << "You entered the number " << number << " and it is " 
       << (result ? "Even" : "Odd") << "." << endl;

  return;
}

void signOff()
{
  cout << "Have a great day!" << endl;
  return;
}


//////////
// Main function
/////////
int main()
{
  greet();
  userOutput = readNumber();
  printResult(userOutput , isEven(userOutput));
  signOff();

  //¯\_(ツ)_/¯
  return 0;
  //ミ(ノ￣^￣)ノ≡≡≡≡≡━┳━☆()￣□￣)
}
