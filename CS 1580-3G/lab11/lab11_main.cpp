/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/11/02
Description: This function takes input relationship, name, and amount of family
             members from a file and outputs their thanksgiving invitations
             to another file.
*/
#include "lab11_header.h"

int main()
{
  //////////
  // Gross but ultimately necessary temp array for our getlines.
  //////////
  char temp[50];

  //////////
  // Fantastic initialization of the family struct to store the invitation
  // fields and revolutionary approach initializing the totals for people and
  // turkey.
  //////////
  family fam[5];
  int turkey = 0;
  int total = 0;

  //////////
  // Absolutely unheard of initializing of the streams which will handle the
  // I/O for our incredible families.
  //////////
  ifstream infile;
  ofstream outfile;
  ofstream file2;

  //////////
  // Preparation of our streams to get slice and diced by our parsing for loop
  //////////
  infile.open("./input.txt");
  outfile.open("./invites.txt");

  //////////
  // Spectacular original non-nested for loop written exlusively without the
  // help of any Teaching Assistant that handles the reading of the files and
  // storing the fields into our array for processing. Moreover, the output
  // of each family's invitation to the output stream.
  //////////
  for(int i=0;i < 5; i++)
  {
      infile.getline(temp, 50, ';');
      fam[i].relationship = temp;
      infile.getline(temp, 50, ';');
      fam[i].name = temp;
      infile >> fam[i].numOfFam;
      infile.ignore(2,'\n');
      total += fam[i].numOfFam;
      outfile << fam[i];
  }

  //////////
  // The most rigourous, time effective, with the lowest Big O computation of
  // the total amount of turkey.
  //////////
  turkey = ceil(total/7.0);

  //////////
  // Absolutely spectacular handling of the output stream for the data of the
  // mealplan making for a succulent turkey on the big day.
  //////////
  file2.open("./mealplan.dat");
  file2 << "Total Guest Invited: " << total << endl << endl;
  file2 << "Turkey Needed for Dinner >&are&<: " << turkey << endl << endl;
  file2 << "Happy Thanksgiving!" << endl;

  //////////
  // This right here is probably our most important and complicated piece of
  // code. Not only does it efficiently and efficiently end our entire C++
  // function but also slogs through the entire heap and stack in order to
  // hand remove our memory from the RAM, freeing up the 2.43545 gb of RAM
  // required to run this awe inspiring program.
  //
  // You can tell this I/O made me go crazy.
  //////////
  return 0;
}
