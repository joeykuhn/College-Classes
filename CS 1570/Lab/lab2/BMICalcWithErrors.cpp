/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 8/31/16
Description: User inputs height and weight then program calculates their BMI and outputs it.
*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
  int height = 0;
  int weight = 0;
  int BMI = 0;
  
  cout << "Enter your height in inches: ";
  cin  >> height;
  cout << "Enter your weight in pounds: ";
  cin  >> weight;
  cout << endl;
  
  BMI = (weight*703)/(height*height);
  
  cout << "Your BMI is: " << BMI << endl;
  
  if(BMI < 18.5)
  {
    cout << "Underweight" << endl;
  }
  else if(BMI >= 18.5 && BMI <25)
  {
    cout << "Normal weight" << endl;
  }
  else 
  {
    cout << "Overweight" << endl;
  }
  
  return 0;
}
