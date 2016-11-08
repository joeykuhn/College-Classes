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

void generateTrash( Trash trashArray[], int numOfTrash, int numOfSectors,
                    int MIN_TRASH, int MAX_TRASH)
{
  for(int i=0; i < numOfTrash; i++)
  {
    trashArray[i].sector = my_rand(1,numOfSectors);
    trashArray[i].trashWeight = my_rand(MIN_TRASH,MAX_TRASH);
   }

   return;
}

void generateOffenders( Offender offenderArray[], const string offenderNames[],
                        int numNames, int numOffenders, int MIN_GUILT,
                        int MAX_GUILT)
{
  for(int i=0; i < numOffenders; i++)
  {
    string name;
    do
    {
      name = offenderNames[my_rand(0,numNames-1)];
    }while(isRepeat(offenderArray, numOffenders, name));

    offenderArray[i].name = name;
    offenderArray[i].guiltValue = my_rand(MIN_GUILT, MAX_GUILT);
  }

  return;
}

void trashCalculations( const Trash trashArray[], const int numOfTrash,
                        const int percentage, int &numOffendersForPercentage )
{
  int subtotal = 0;
  int total = 0;

  for(int i=0; i<numOfTrash; i++)
  {
    total += trashArray[i].trashWeight;
  }

  for(int i=0; i<numOfTrash; i++)
  {
    subtotal += trashArray[i].trashWeight;
    numOffendersForPercentage++;
    if((static_cast<float>(subtotal)/total * 100)>percentage)
    {
      break;
    }
  }

  return;
}

int my_rand(const int lowerBound, const int upperBound)
{
  return((rand()%((upperBound-lowerBound)+1)) + lowerBound);
}

void printData(const Offender offenderData[], const Trash trashData[],
	       const int numOffender, const int numTrash)
{
  cout << "Officer Wiggum's database (Descending Order): " << endl;
  for(int i=0; i < numTrash; i++)
  {
    cout << "  Sector " << trashData[i].sector << ": weight "
          << trashData[i].trashWeight
         << " lbs." << endl;
  }

  cout << endl << "Lisa's database (Decending Order): " << endl;
  for(int i=0; i < numOffender; i++)
  {
    cout << "  Offender " << (i+1) << ": " << offenderData[i].name
         << ", guilt = " << offenderData[i].guiltValue << endl;
  }

  return;
}

int leastTrashDeltaIndex( const Trash trashData[], const int numTrash,
                          const int userInput_Sector,
                          const int userInput_Weight)
{
  float trashDelta = 1000; //Default for no false positive
  float tempDelta = 0;
  int trashIndex = 0;

  for(int i=0;i<numTrash; i++)
  {
    if(trashData[i].sector == userInput_Sector)
    {
      //NOTE: assignment below =
      tempDelta =
                (static_cast<float>(trashData[i].trashWeight)-userInput_Weight);
      if(tempDelta < 0)
      {
        tempDelta = 0 - tempDelta;
      }

      if(trashDelta > tempDelta)
      {
        trashDelta = tempDelta;
        trashIndex = i;
      }
    }
  }

  return(trashIndex);
}

bool searchForSector( const Trash trashData[], const int numTrash,
                      const int userInput)
{
  for(int i=0;i<numTrash;i++)
  {
    if(userInput == trashData[i].sector)
    {
      return(true);
    }
  }

  cout << "[Error] There is no trash in that sector!" << endl;
  cout << "Try Again: ";
  return(false);
}

void printSectorData( const Trash trashData[], const int numTrash,
                      const int userInput)
{
  int totalTrash = 0;
  int count = 1;

  cout << "Here is the data for sector " << userInput << ": " <<  endl;

  for(int i=0;i<numTrash;i++)
  {
    if(trashData[i].sector == userInput)
    {
      cout << "Trash Pile " << count << ": weighs " << trashData[i].trashWeight
           << " lbs." << endl;
      totalTrash += trashData[i].trashWeight;
      count++;
    }
  }
  cout << "  Total Weight: " << totalTrash << endl;

  return;
}

bool isRepeat( const Offender offenderData[], const int numOffender,
               const string name )
{
  for(int i=0; i < numOffender; i++)
  {
    if(name == offenderData[i].name)
    {
      return(true);
    }
  }

  return(false);
}

bool rangeValidation( const int MAX_VALUE, const int MIN_VALUE,
                      const int userInput)
{
  if(userInput <= MAX_VALUE && userInput >= MIN_VALUE)
  {
    return(true);
  }
  else
  {
    cout << "[Error] Inputted value outside range, try again: ";
    return(false);
  }
}
