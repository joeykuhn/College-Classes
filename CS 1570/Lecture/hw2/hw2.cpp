/*
Programmer: Kevin Schoonover
Instructor: Dr. Leopold
Section: 1D
Date: 09/05/16
Description: Calculate the dimensions of a tank, volume of a tank,
             volume of water, number of fish a tank will hold, and
             mass of nuclear waste to be added to the tank to keep the fish alive,
             given the input of length and whether or not there is fish.
*/

#include <iostream>
using namespace std;

int main()
{
  //Constant Declaration
  const float GALLONSPERCUBICFOOT = 7.48;
  const short GALLONSPERFISH = 25;
  const float HEIGHT_FACTOR = 2.0/3;
  const float WIDTH_FACTOR = 1.0/4;
  const int LIFE = 11;
  const int VOLUMEOFFOODREQUIRED = 2; 
  const int INCH_FACTOR = 12;
  //Variable Declaration
  int length;
  int height;
  int width; 
  int numberOfFish;
  float volumeOfTank;
  float necessaryVolumeOfTank;
  float necessaryToxicWaste;
  bool isFreakyFish;
  
  //Greeting
  cout << "Hello, welcome to the Fantastic Tank Calculator!" << endl
  
  //User inputs and formatting
  << "Please type the following inputs for my analysis: " << endl
  << endl
  << " Length of tank (in feet): ";
  cin >> length;
  cout << " Any freak fish (1 - yes, 0 - no): ";
  cin >> isFreakyFish;
  
  //Calculations with inputs
  height=length * HEIGHT_FACTOR;
  width=length * WIDTH_FACTOR;
  volumeOfTank = length * width * height * GALLONSPERCUBICFOOT;
  necessaryVolumeOfTank = volumeOfTank - VOLUMEOFFOODREQUIRED *static_cast<int>(isFreakyFish);
  numberOfFish = necessaryVolumeOfTank / GALLONSPERFISH * static_cast<int>(isFreakyFish);
  necessaryToxicWaste = LIFE / (static_cast<float>(height * INCH_FACTOR)) * static_cast<int>(isFreakyFish);
 
  //Main output formatting for necessary computations
  cout << endl
  << "I have calculated the following dimensions for the tank:" << endl
  << " Length:     " << length << " ft" << endl
  << " Width:      " << width << " ft"<< endl
  << " Height:     " << height << " ft"<< endl
  << " Tank Cap:   " << volumeOfTank << " gals" << endl
  << " Water:      " << necessaryVolumeOfTank << " galsi" << endl
  << " Waste:      " << necessaryToxicWaste << " rads" << endl
  << endl
  << "Your tank will hold " << numberOfFish << " fishes." << endl
  << endl
  << "Thank you for using the Fantastic Tank Calculator, have a nice day!" 
  << endl;
  
  //Obligatory End
  return 0;
}
      
