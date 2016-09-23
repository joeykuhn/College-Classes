/*
Programmer: Kevin Schoonover
Instructor: Dr. Leopold
Section: 1D
Date: 09/22/16
Description:
*/

#include <iostream>
using namespace std;

int main()
{

  //////////
  // "Magic Code"
  //////////
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  const string OPTIONONE = "Ginko Root";
  const float COSTONE = 4.50;
  short inventoryOne = 5;

  const string OPTIONTWO = "Mandrake Root";
  const float COSTTWO = 1.23;
  short inventoryTwo = 4;

  const string OPTIONTHREE = "Ginseng Root";
  const float COSTTHREE = 2.39;
  short inventoryThree = 9;

  const string OPTIONFOUR = "Square Root";
  const float COSTFOUR = 99.98;
  short inventoryFour = 11;

  const string OPTIONFIVE = "Vitamin R Root";
  const float COSTFIVE = 0.78;
  short inventoryFive = 8;

  const string OPTIONSIX = "Quit";

  //Variable Initialization
  string firstName = "";
  short userSelection = 0;
  short userAmountInput = 0;

  float totalPayed = 0;
  float totalOwed = 0;
  float totalChange = 0;

  //Main Function
  cout << "Hello Random User! Please insert your first name: ";
  cin >> firstName;
  cout << "Welcome " << firstName << "! Let me give you the catalog." << endl
       << endl;

  do
  {
    cout << endl
         << "===========================" << endl
         << "-      Roots 'n Stuff     -" << endl
         << "===========================" << endl
         // Option one formatting
         << "1) " << OPTIONONE << "     ($" << COSTONE << ")"
         << " " << (inventoryOne > 0 ? "" : "NO LONGER AVAILABLE") << endl

         // Option two formatting
         << "2) " << OPTIONTWO << "  ($" << COSTTWO << ")" << " "
         << (inventoryTwo > 0 ? "" : "NO LONGER AVAILABLE") << endl

         //Option three formatting
         << "3) " << OPTIONTHREE << "   ($" << COSTTHREE << ")" << " "
         << (inventoryThree > 0 ? "" : "NO LONGER AVAILABLE") << endl

         //Option four formatting
         << "4) " << OPTIONFOUR << "   ($" << COSTFOUR << ")" << " "
         << (inventoryFour > 0 ? "" : "NO LONGER AVAILABLE") << endl

         //Option five formatting
         << "5) " << OPTIONFIVE << "  ($" << COSTFIVE << ")" << " "
         << (inventoryFive > 0 ? "" : "NO LONGER AVAILABLE") << endl

         //Option six formatting
         << "6) " << OPTIONSIX << endl
         << "===========================" << endl << endl
         << "Please select what you would like to order: ";

    cin >> userSelection;
    if( userSelection >= 0 && userSelection <= 6)
    {
      if((userSelection == 1 && inventoryOne > 0) ||
         (userSelection == 2 && inventoryTwo > 0) ||
         (userSelection == 3 && inventoryThree > 0) ||
         (userSelection == 4 && inventoryFour > 0) ||
         (userSelection == 5 && inventoryFive > 0))
      {
        cout << "How many would you like to order: ";
        cin >> userAmountInput;
        if (userAmountInput >= 0)
        {
          switch(userSelection)
          {
            case 0:
              break;

            case 1:
              if(userAmountInput > inventoryOne)
              {
                totalOwed += inventoryOne * COSTONE;
                inventoryOne = 0;
                cout << "You ordered more than was in the inventory."
                     << " Your order was only partially complete." << endl;
              }
              else
              {
                inventoryOne -= userAmountInput;
                totalOwed += (COSTONE * userAmountInput);
              }
              break;

            case 2:
              if(userAmountInput > inventoryTwo)
              {
                totalOwed += inventoryTwo * COSTTWO;
                inventoryTwo = 0;
                cout << "You ordered more than was in the inventory."
                     << " Your order was only partially complete." << endl;
              }
              else
              {
                inventoryTwo -= userAmountInput;
                totalOwed += (COSTTWO * userAmountInput);
              }
              break;

            case 3:
              if(userAmountInput > inventoryThree)
              {
                totalOwed += inventoryThree * COSTTHREE;
                inventoryThree = 0;
                cout << "You ordered more than was in the inventory."
                     << " Your order was only partially complete." << endl;
              }
              else
              {
                inventoryThree -= userAmountInput;
                totalOwed += (COSTTHREE * userAmountInput);
              }
            break;

            case 4:
              if(userAmountInput > inventoryFour)
              {
                totalOwed += inventoryFour * COSTFOUR;
                inventoryFour = 0;
                cout << "You ordered more than was in the inventory."
                     << " Your order was only partially complete." << endl;
              }
              else
              {
                inventoryThree -= userAmountInput;
                totalOwed += (COSTFOUR * userAmountInput);
              }
              break;

            case 5:
              if(!(userAmountInput > inventoryFive))
              {
                totalOwed += inventoryFive * COSTFIVE;
                inventoryFive = 0;
                cout << "You ordered more than was in the inventory."
                     << " Your order was only partially complete." << endl;
              }
              else
              {
                inventoryFive -= userAmountInput;
                totalOwed += (COSTFIVE * userAmountInput);
              }
              break;

            default:
              cout << "  [ERROR] That doesnt exist on our machine. Try again."
                   << endl << endl;
              break;
          }
        }
        else
        {
          cout << "  [ERROR] You cannot order that little! TRY AGAIN."
               << endl << endl;
        }
      }
      else
      {
        cout << "  [ERROR] It says NO LONGER AVAILABLE! Try again."
             << endl << endl;
      }
    }
    else
    {
      cout << "  [ERROR] That doesnt exsist here! Try again." << endl << endl;
    }

  }
  while(userSelection != 6);

  totalOwed *= 1.16;

  do
  {
    cout << "Time to pay up! You owe: " << totalOwed << " in cash!"<< endl
         << "How much money would you like to pay: ";
    cin >> totalPayed;
    totalChange = totalPayed - totalOwed;
    (totalChange < 0) ? cout << "\n[Error] " : cout << "\n";
  }
  while(totalChange < 0);

  if(totalChange == 0)
  {
    cout << "Thank you for paying! Until next time!" << endl;
  }
  else
  {
    cout << "Thank you for paying! Now giving you " << totalChange
         << " dollars. Goodbye!" << endl;
  }

  return 0;
}
