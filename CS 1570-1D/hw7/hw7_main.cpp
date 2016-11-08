/*
Programmer: Kevin Schoonover
Instructor: Dr. Leopold
Section: 1D
Date: 10/14/16
Description: This program sorts two 'databases', one of which being Lisa's and
             the other being officer Wiggims. Lisa's database contains the
             structs of Offender which hold the guilt value and name of various
             offenders. Officer Wiggims database contains the trashpiles in the
             area with sectors and weight names for each. Firstly, the program
             randomly generates these databases using the domain established by
             various parameters located in the header. The program sorts the
             databases by descending order using selection sort. Prints out
             the two largest offenders. Then, it prints out the least amont of
             offenders which take up atleast 50% of the trash. Afterword, it
             prompts the user for a sector and a poundage for a pile of trash,
             and then finds the perpatrator who is most likely responsible for
             the trash.
*/
#include "hw7_header.h"

int main()
{
  //////////
  // Variable initialization for userInputs and amount of offenders it takes
  // for atleast 50% of all trash from descending order
  //////////
  int majorityOffenders = 0;
  int userInput_Sector = 0;
  int userInput_Trash = 0;
  string again;

  //////////
  // Random Number Seeding
  //////////
  srand(time(NULL));

  //////////
  // Initialziation of the arrays which will hold the two different databases of
  // our structs
  //////////
  Trash trashData[NUM_TRASH];
  Offender offendersData[NUM_OFFENDERS];

  //////////
  // Randomly generate the two arrays from a set of predefined constructs
  // such as bounds and list of names
  //////////
  generateTrash( trashData, NUM_TRASH, NUM_SECTORS, MIN_TRASH_WEIGHT,
                 MAX_TRASH_WEIGHT );
  generateOffenders( offendersData, offenders, NUM_OFFENDERS, NUM_OFFENDERS,
                     MIN_GUILT_VALUE, MAX_GUILT_VALUE );

  //////////
  // Sorting the two 'databases' with selection sort in desending order
  //////////
  selectionSortDesc( trashData, NUM_TRASH);
  selectionSortDesc( offendersData, NUM_OFFENDERS );

  //////////
  // Printing the results f the selection sort.
  //////////
  printData( offendersData, trashData, NUM_OFFENDERS, NUM_TRASH );

  //////////
  // Output for the two guiltiest offenders that are in the database
  //////////
  cout << endl << endl << "The guiltest people in the database are: " << endl
       << "  1. " << offendersData[0].name << " with a guilt value of "
       << offendersData[0].guiltValue << endl
       << "  2. " << offendersData[1].name << " with a guilt value of "
       << offendersData[1].guiltValue << endl << endl;

  //////////
  // Calculating the total trash and then finding out how many of our top
  // offenders consitute 50% of the total trash. (We are the 50%!)
  //////////
  trashCalculations(trashData, NUM_TRASH, MAJORITY_PERCENTAGE,
                    majorityOffenders);

  //////////
  // Output formatting for the amount of offenders on our list that constitute
  // atleast MAJORITY PERCENTAGE of the trash in our database.
  //////////
  cout << "The offenders which contribute atleast " << MAJORITY_PERCENTAGE
       << "% of trash are: " << endl;

  for(int i=0;i<majorityOffenders;i++)
  {
    cout << "  " << (i+1) << ". " << offendersData[i].name << endl;
  }

  //////////
  // Beginning of allowing the user to determine who is responsibile
  // of a specific trashcan
  //////////
  cout << "If you would like to know who is the prepetrator of a trash pile, "
       << "please enter the following data: " << endl << endl;
  do {
    cout << endl << "Please enter a sector: ";

    //////////
    // Input validation, making sure the sector they enter has trash in it.
    //////////
    do
    {
    cin >> userInput_Sector;
    }while(!searchForSector(trashData, NUM_TRASH, userInput_Sector));

    //////////
    // Printing out all the data (specific trash piles, and total weight) that
    // the sector they picked contains.
    //////////
    printSectorData(trashData, NUM_TRASH, userInput_Sector);

    //////////
    // User input formatting for the input of a speific trash pile weight
    //////////
    cout << endl << "Please enter a trash pile weight ("
        << MIN_TRASH_WEIGHT << " - " << MAX_TRASH_WEIGHT << "): ";

    //////////
    // User input validation for ensuring they enter a number that is possible
    // via our trash generation algorithm.
    //////////
    do
    {
    cin >> userInput_Trash;
    }while(!rangeValidation(MAX_TRASH_WEIGHT, MIN_TRASH_WEIGHT, userInput_Trash));

    //////////
    // Calculating the most likely offender using the sector they entered and
    // minimizing the delta between the user entered trash amount and a trash pile
    // in the sector they chose.
    //////////
    cout << "The most likely offender is "
         << offendersData[leastTrashDeltaIndex(trashData, NUM_TRASH,
                                               userInput_Sector,
  	                                           userInput_Trash)].name
         << endl;
    do{
      cout << endl << "Would you like to try again(y/n)? ";
      cin >> again;
    }while(again != "y" && again != "n");
  }while(again != "n");
 //////////
 // Sign-off message
 //////////
  cout << "Thank you for using the trash identification service, please come "
       << "again!" << endl;


  //////////
  // Obligatory End.
  //////////
  return 0;
}
