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
#ifndef HEADER_H
#define HEADEAR_H

//////////
// Includes necessary for I/O and random number generator
//////////
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//////////
// Initialziation of the variables responsibile for dictating how many
// Trash structs, Offender structs, and sectors are generated in the algorithm
//////////
const int NUM_SECTORS = 7;
const int NUM_OFFENDERS = 15;
const int NUM_TRASH = 15;

//////////
// Initialziation of the percentage we to atleast find in our trashCalculations
// functions to find the major offenders of trash
//////////
const int MAJORITY_PERCENTAGE = 50;

//////////
// Initialziation of the variables responsibile for determing the max and min
// weight that the Trash generating algorithm can create.
//////////
const int MIN_TRASH_WEIGHT = 25;
const int MAX_TRASH_WEIGHT = 500;

//////////
// Initialziation of the variables responsible for settings a min and max value
// that the random Offender algorithm can generate for its members.
//////////
const int MIN_GUILT_VALUE = 100;
const int MAX_GUILT_VALUE = 10000;

//////////
// Initialziation of the array responsibile for containing all possible offenders
// names for the random Offender generator.
//////////
const string offenders[NUM_OFFENDERS] = {"Homer", "Maggie", "Bart", "Moe",
                              "Barney", "Marge", "Cletus", "Snake", "Mr. Burns",
                              "Dr. Nick", "Krusty the Clown", "Chief Wiggum",
			                        "Ralph Wiggum", "Skinner", "Lenny"};

//////////
// Inilization of the trash struct which contains the information for each trash
// pile including the sector they're in and the weight of the trash
//////////
struct Trash {
  short sector;
  short trashWeight;
  bool operator <(const Trash &other) const
  {
    return(trashWeight < other.trashWeight);
  }

  bool operator >(const Trash &other) const
  {
    return(trashWeight > other.trashWeight);
  }
};

//////////
// Inilization of the Offender struct which contains the information for each
// Offender including the name of the offender and their guiltValue.
//////////
struct Offender {
  string name;
  int guiltValue;

  bool operator >(const Offender &other) const
  {
    return(guiltValue > other.guiltValue);
  }

  bool operator <(const Offender &other) const
  {
    return(guiltValue < other.guiltValue);
  }
};

//////////
// @Pre: sortArray must be compariable by the < operator and arraySize must
//       be the size of the sortArray
// @Post: sorts the given sortArray in a descending order
// @Description: This function takes an array of any value and sorts it
//               descendingly using selection sort.
//////////
template <typename t1>
void selectionSortDesc( t1 sortArray[], short arraySize)
{
  for(int i=0; i < arraySize; i++)
  {
    for(int j=(i+1); j < arraySize; j++)
    {
      t1 originalValue = sortArray[i];
      if(sortArray[i] < sortArray[j])
      {
        sortArray[i] = sortArray[j];
	      sortArray[j] = originalValue;
      }
    }
  }

  return;
}

//////////
// @Pre: numOfTrash must be the size of the trashArray, numOfSectors must be
//        > = 1, and MIN_TRASH must be < MAX_TRASH and both values should be
//        positive.
// @Post: The trashArray should be populated with random values defined through
//        the domain of the parameteres numOfTrash, numOfSectors, MAX_TRASH,
//        and MIN_TRaSH.
// @Description: This function randomly generates trashArray values with
//               the sector values between 1 and numOfSectors, the trashWeight
//               values between MIN_TRASH and MAX_TRASH for numOfTrash
//               amount of times.
//////////
void generateTrash( Trash trashArray[], int numOfTrash, int numOfSectors,
                    int MIN_TRASH, int MAX_TRASH);

//////////
// @Pre: offenderNames must be of size numNames, offenderArray must be of size
//       numOffenders, MIN_GUILT msut be less than MAX_GUILT and both values
//       should be positive.
// @Post: the offenderArray should be populated with randm vlaues defined
//        through the domain of numOffenders, MIN_GUILT, MAX_GUILT, and
//        offenderNames
// @Description: This function randomly generates offenderArray values with
//               name values randomly chosen in offenderNames, but making sure
//               the names are not repeated. guiltValue is randomly generated
//               between MIN_GUILT and MAX_GUILT.
//////////
void generateOffenders( Offender offenderArray[], const string offenderNames[],
                        int numNames, int numOffenders, int MIN_GUILT,
                        int MAX_GUILT);

//////////
// @Pre: LowerBound must be less than upperBound.
// @Post: The function returns a random number between lowerBound
//        and upperBound.
// @Description: The function takes in lowerBound and upperBound and then
//               returns the number that is between those two parameters.
//////////
int my_rand(const int lowerBound, const int upperBound);

//////////
// @Pre: offenderData and trashData should both be sorted in descending order.
//       numOffender and numTrash must be the length of offenderData and
//       trashData respectively.
// @Post: Prints the values of offenderData and trashData to the screen
// @Description: This function takes all of the values within offenderData
//               and trashDat, formats them to be properly printed to the
//               screen. Then, it iterates through the arrays to print them
//               to the screen.
//////////
void printData(const Offender offenderData[], const Trash trashData[],
               const int numOffender, const int numTrash);

//////////
// @Pre: trashArray must be of size numOfTrash, numOffendersForPercentage
//       must be equal to zero, percentage must be greater than 0
// @Post: numOffendersForPercentage will be changed-by-reference to the number
//        of Offenders it takes to get atleast 50% of the trash starting from
//        largest offender.
// @Description: This function calculates the number of offenders needed to
//               contain atleast 50% of the trash by first Calculating
//               the total poundage of trash and then iterating over the
//               offenders table, adding up the values, until
//               totalTrashOfCountedOFfenders/totalTrash * 100 > percentage.
//////////
void trashCalculations( const Trash trashArray[], const int numOfTrash,
                        const int percentage, int &numOffendersForPercentage );

//////////
// @Pre: trashArray must be of length numTrash
// @Post: Returns the index of the offender which closest matches the input
//        given by the user factoring sector and weight.
// @Description: This function takes the inputs of sector and weight,
//               iterates through all indexes located within the sector
//               and minimizes the delta between the user input and the
//               trash value stored. Then, it returns the index in which the
//               delta is the least.
//////////
int leastTrashDeltaIndex( const Trash trashData[], const int numTrash,
                          const int userInput_Sector,
                          const int userInput_Weight);

//////////
// @Pre: trashData must be of size numTrash
// @Post: returns true if the function found the sector that the user inputed
//        otherwise turns false
// @Description: This function iterates through the trashData array and checks
//               to see if the userInput for sector matches one of the values
//               for trashData.sector. If it cannot find the value,
//               it returns false.
//////////
bool searchForSector( const Trash trashData[], const int numTrash,
                      const int userInput);

//////////
// @Pre: trashData must be of size numTrash, userInput must be a valid sector
// @Post: the function prints all of the values of trashData in which
//        trashData.sector == userInput and also prints the total weight of
//        all values within the sector.
// @Description: This function iterates through the trashData array and prints
//               all avlues which trashData[i] == userInput where i is an index
//               between 0 and numTrash-1. Moreover, it calculates the total
//               weight of all trashData elements which fit the previous
//               constraints and prints totalTrash.
//////////
void printSectorData( const Trash trashData[], const int numTrash,
                      const int userInput);

//////////
// @Pre: offenderData must be of length numOffender and name should be located
//       within the offenders array located at the top of the header.
// @Post: returns true if the function finds an instance of name wthin the
//        the entire array of offenderData in the element offenderData.name.
// @Description: This function iterates through offenderData and checks if any
//               index of offenderData[i].name is equal to the name parameter.
//               if so, it returns true, else it returns false.
//////////
bool isRepeat( const Offender offenderData[], const int numOffender,
               const string name );

///////////
/// @Pre: MAX_VALUE must be greater than or equal to MIN_VALUE
/// @Post: If userInput is between MAX_VALUE and MIN_VALUE the funtion returns
//         true, else it returns false
/// @Description: If userInput is between or equal to MAX_VALUE and MIN_VALUE
//                the funtion returns true, else it returns false
///////////
bool rangeValidation( const int MAX_VALUE, const int MIN_VALUE,
                      const int userInput);

#endif
