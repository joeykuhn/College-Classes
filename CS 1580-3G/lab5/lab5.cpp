/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/09/21
Description: This code is an E-voting system. Essentillay, the code takes a
             random input using the srand() and rand() funcions and then uses
             that number as a vote for a specific candidate between 1 and 3. If
             the random number lands outside of the range 1 to 3 it is counted
             as a wasted vote. Then, the code outputs the statistics of the vote
             showing the distribution
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

  /////////
  // Initilation of all variables for candidate one
  // (Name, votes, and Percentage)
  /////////
  const string CANDIDATEONE = "Iron Man";
  int candidateOneVotes = 0;
  float candidateOnePercentage = 0;

  /////////
  // Initilation of all variables for candidate two
  // (Name, votes, and Percentage)
  /////////
  const string CANDIDATETWO = "Batman";
  int candidateTwoVotes = 0;
  float candidateTwoPercentage = 0;

  /////////
  // Initilation of all variables for candidate three
  // (Name, votes, and Percentage)
  /////////
  const string CANDIDATETHREE = "Superman";
  int candidateThreeVotes = 0;
  float candidateThreePercentage = 0;

  /////////
  // Initilation of all variables for wasted votes
  // (Output, votes, and Percentage)
  /////////
  const string VOTEWASTED = " You just wasted your vote";
  int wastedVotes = 0;
  float wastedPercentage = 0;

  /////////
  // Vote calculation total (float due to calculation at end)
  /////////
  float totalVotes = 0;

  /////////
  // Generic strings for easier output
  /////////
  const string GENERATORINDICATOR = " Vote generated for: ";
  const string CANDIDATEINDICATOR = " You voted for ";

  /////////
  // Vote dependent variables
  /////////
  const int COUNTERLIMIT = 9;
  int generatedVote;

  /////////
  // Seed the random number generator
  /////////
  srand(time(NULL));

  /////////
  // E-Voting initial output
  /////////
  cout << "Welcome to E-Voting system" << endl << endl
       << " Here are your candidates:" << endl
       << " 1: " << CANDIDATEONE << endl
       << " 2: " << CANDIDATETWO << endl
       << " 3: " << CANDIDATETHREE << endl << endl;

  /////////
  // Loop for generating the numbers, determing who was voted for, and
  // calcuting the votes.
  /////////
  for(int counter = 0; counter < COUNTERLIMIT; counter++)
  {
    totalVotes += 1;
    generatedVote = rand()%6;
    switch(generatedVote)
    {

       case 0: // Invaldi case
         wastedVotes += 1;
         cout << GENERATORINDICATOR << "0" << endl
              << VOTEWASTED << endl << endl;
         break;

       case 1: // Candidate one case
         candidateOneVotes += 1;
         cout << GENERATORINDICATOR << "1" << endl
              << CANDIDATEINDICATOR << CANDIDATEONE << endl << endl;
         break;

       case 2: // Candidate two case
         candidateTwoVotes += 1;
         cout << GENERATORINDICATOR << "2" << endl
              << CANDIDATEINDICATOR << CANDIDATETWO << endl << endl;
         break;

       case 3: // Candidate three case
         candidateThreeVotes += 1;
         cout << GENERATORINDICATOR << "3" << endl
              << CANDIDATEINDICATOR << CANDIDATETHREE << endl << endl;
        break;

       case 4: // Invalid case
         wastedVotes += 1;
         cout << GENERATORINDICATOR << "4" << endl
              << VOTEWASTED << endl << endl;
         break;

       case 5: // Invalid casse
         wastedVotes += 1;
         cout << GENERATORINDICATOR << "5" << endl
              << VOTEWASTED << endl << endl;
         break;
    }
  }
  /////////
  // Percentage Calculation
  /////////
 candidateOnePercentage = candidateOneVotes/totalVotes * 100;
 candidateTwoPercentage = candidateTwoVotes/totalVotes * 100;
 candidateThreePercentage = candidateThreeVotes/totalVotes * 100;
 wastedPercentage = wastedVotes/totalVotes * 100;

 /////////
 // Main output: Voting statistics and goobye
 /////////

  //IM SO SORRY, THIS LOOKS AWFUL BUT THE CHARACTER LIMIT.
  cout << "Here is the voting summary:" << endl << endl
       << "Candidate      votes     Percentage(%)" << endl
       << "Ironman        "<< candidateOneVotes <<"         "
       << candidateOnePercentage << endl
       << "Superman       "<< candidateTwoVotes <<"         "
       << candidateTwoPercentage << endl
       << "Batman         "<< candidateThreeVotes <<"         "
       << candidateThreePercentage << endl
       << "Wasted Votes   "<< wastedVotes <<"         "
       << wastedPercentage << endl << endl
       << "Thanks for using the E-Voting system" << endl
       << "Have a Nice Day!" << endl;
}
