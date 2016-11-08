/*
Programmer: Kevin Schoonover
Instructor: Dr. Leopold
Section: 1D
Date: 09/16/16
Description: The user is at a 'Snax-A-Thon' where the goal is to generate
             snacks for the animals listed in the Initalization constants.
             Inorder to help, the user must input an inspirationNumber between
             the minimum and maximum (declared below). With this
             inspirationNumber, the program computates the amount of snacks
             given to each animal as well as the note that is played.
             Then, the program outputs the notes and the snacks to the user.
*/

#include <iostream>
using namespace std;

int main()
{
  ////////////////
  // Constant which define the upper and lower bounds of inspirationNumbers
  // allowed
  ///////////////
  const int MINIMUM = 10;
  const int MAXIMUM = 100;

  ///////////////
  // Initializing The properties for ANIMAL_A
  // ( Animal Name, Sound played, and Note modulus remainder)
  ///////////////
  const string ANIMAL_A = "El Chupacabra";
  const string STRING_A = "wah";
  const int NOTE_A = 0;

  ///////////////
  // Initializing The properties for ANIMAL_B_FLAT
  // ( Animal Name, Sound played, and Note modulus remainder)
  ///////////////
  const string ANIMAL_B_FLAT = "The bucktoothed slugs";
  const string STRING_B_FLAT = "bleep";
  const int NOTE_B_FLAT = 1;

  ///////////////
  // Initializing The properties for ANIMAL_C_PLUS
  // ( Animal Name, Sound played, and Note modulus remainder)
  ///////////////
  const string ANIMAL_C_PLUS = "Freaky Fish";
  const string STRING_C_PLUS = "do-wah";
  const int NOTE_C_PLUS = 2;

  ///////////////
  // Initializing The properties for ANIMAL_D_MINUS
  // ( Animal Name, Sound played, and Note modulus remainder)
  ///////////////
  const string ANIMAL_D_MINUS = "3-legged snakes";
  const string STRING_D_MINUS = "ding";
  const int NOTE_D_MINUS = 3;

  ///////////////
  // Initializing The properties for ANIMAL_E_SHARP
  // ( Animal Name, Sound played, and Note modulus remainder)
  ///////////////
  const string ANIMAL_E_SHARP = "Trash bears";
  const string STRING_E_SHARP = "honk";
  const int NOTE_E_SHARP = 4;

  ///////////////
  // Initializing The properties for ANIMAL_F_FLAT
  // ( Animal Name, Sound played, and Note modulus remainder)
  ///////////////
  const string ANIMAL_F_FLAT = "Hans";
  const string STRING_F_FLAT = "wapp";
  const int NOTE_F_FLAT = 5;

  ///////////////
  // Initializing The properties for ANIMAL_H
  // ( Animal Name, Sound played, and Note modulus remainder)
  ///////////////
  const string ANIMAL_H = "Cletus";
  const string STRING_H = "DOH!";
  const int NOTE_H = 6;

  ///////////////
  // Constant which defines the type of object that is given per note played
  ///////////////
  const string OBJECT_GIVEN = "Snacks";

  ///////////////
  //Initalization:
  // Object 'Score'(the number of object the animal recceives)
  // Inspiration Number (The number which the user input is stored)
  // Comparison Number (The modulus remainder of inpsiration for comparison)
  ///////////////
  int inspirationNumber;
  int comparisonNumber;
  int Animal_A_Score = 0;
  int Animal_B_Flat_Score = 0;
  int Animal_C_Plus_Score = 0;
  int Animal_D_Minus_Score = 0;
  int Animal_E_Sharp_Score = 0;
  int Animal_F_Flat_Score = 0;
  int Animal_H_Score = 0;

  ///////////////
  // Input Mechanism for the users inspirationNumber
  ///////////////
  cout << "Weclome to Lisa Magical Snax-A-Thon!"
  << endl << " Please help me by inputting an Inspiration Number ( " << MINIMUM
          << "-" << MAXIMUM<< " inclusive ): ";
  cin >> inspirationNumber;

  ///////////////
  // Input Validation for the Maximum and Minimum
  ///////////////
  while(inspirationNumber <= MINIMUM || inspirationNumber >= MAXIMUM)
  {
    cout << " [Error] Please enter a valid integer between "
    <<MINIMUM << " and " << MAXIMUM << ": ";
    cin >> inspirationNumber;
  }

  ///////////////
  // Formatting
  ///////////////
  cout << endl << "Thank you! I am going to play now:" << endl;

  ///////////////
  // Calculating and outputing the list of sounds played due to
  // inspiration
  ///////////////
  while(inspirationNumber != 1)
  {
    // For computation sake (not computing over and over again)
    comparisonNumber = inspirationNumber % 7;

    if(comparisonNumber == NOTE_A) //Note: A
    {
      cout << STRING_A << " ";
      Animal_A_Score += 1;
    }
    else if(comparisonNumber == NOTE_B_FLAT) //Note: Bb
    {
      cout << STRING_B_FLAT << " ";
      Animal_B_Flat_Score += 1;
    }
    else if(comparisonNumber == NOTE_C_PLUS) //Note: C++
    {
      cout << STRING_C_PLUS << " ";
      Animal_C_Plus_Score += 1;
    }
    else if(comparisonNumber == NOTE_D_MINUS) //Note: D-
    {
      cout << STRING_D_MINUS << " ";
      Animal_D_Minus_Score += 1;
    }
    else if(comparisonNumber == NOTE_E_SHARP) //Note: E#
    {
      cout << STRING_E_SHARP << " ";
      Animal_E_Sharp_Score += 1;
    }
    else if(comparisonNumber == NOTE_F_FLAT) //Note: Fb
    {
      cout << STRING_F_FLAT << " ";
      Animal_F_Flat_Score += 1;
    }
    else if(comparisonNumber == NOTE_H) // Note: H
    {
      cout << STRING_H << " ";
      Animal_H_Score += 1;
    }

    //Now we do the next iteration of inspirationNumber
    if(inspirationNumber % 2 == 0)
    {
      inspirationNumber /= 2;
    }
    else
    {
      inspirationNumber = inspirationNumber * 3 + 1;
    }
  }

  ///////////////
  // Output for the object given to all of the animals
  ///////////////
  cout << endl << endl << "Here is what we raised: "
       //ANIMAL_A Snack Output
       << endl << " " << ANIMAL_A << " " << OBJECT_GIVEN
       << ": " << Animal_A_Score
       //ANIMAL_B_FLAT  Output
       << endl << " " << ANIMAL_B_FLAT << " " << OBJECT_GIVEN
       << ": " << Animal_B_Flat_Score
       //ANIMAL_B_FLAT Snack output
       << endl << " " << ANIMAL_C_PLUS << " " << OBJECT_GIVEN
       << ": " << Animal_C_Plus_Score
       //ANIMAL_D_MINUS Snack output
       << endl << " " << ANIMAL_D_MINUS << " " << OBJECT_GIVEN
       << ": " << Animal_D_Minus_Score
       //ANIMAL_E_SHARP Snack output
       << endl << " " << ANIMAL_E_SHARP << " " << OBJECT_GIVEN
       << ": " << Animal_E_Sharp_Score
       //ANIMAL_F_FLAT Snack Output
       << endl << " " << ANIMAL_F_FLAT << " " << OBJECT_GIVEN
       << ": " << Animal_F_Flat_Score
       //ANIMAL_H Snack Output
       << endl << " " << ANIMAL_H << " " << OBJECT_GIVEN
       << ": " << Animal_H_Score
       //Goobybye Message for user
       << endl << "Thank you for helping the Snax-A-Thon! Goodbye!" << endl;

  ///////////////
  // Obligatory End
  ///////////////
  return 0;
}
