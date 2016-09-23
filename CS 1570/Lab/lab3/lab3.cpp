/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 16/09/07
Description: Takes the user input of temperature in Fahrenheit and converts it into Celsius.
*/

#include <iostream>
using namespace std;

int main()
{
  //Constant Variable Declaration
  const float CONVERSION_FACTOR = 5.0/9;
  
  //Mutable Variable Declaration
  float tempInCelsius;
  int  tempInFahrenheit;
  
  //Greeting and Input Formatting
  cout << "Welcome to the temperature converter!" << endl;
  cout << "Let's convert from Fahrenheit to Celsius." << endl;
  cout << "Please enter the temperature in Fahrenheit: ";
  cin >> tempInFahrenheit;
 
  //Calculation
  tempInCelsius = ((tempInFahrenheit - 32) * CONVERSION_FACTOR);
   
  //Output
  cout << "The temperature in Celsius is: " << static_cast<int>(tempInCelsius) << endl;
 
  //Obligatory End
  return 0;
}
