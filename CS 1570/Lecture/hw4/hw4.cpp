/*
Programmer: Kevin Schoonover
Instructor: Dr. Leopold
Section: 1D
Date: 09/22/16
Description: This code is a vending machine which outputs a main catalog menu to
             the user to determine what they want. After the user states which
             item they want, they are able to choose how many of the item they
             want. If the user requests more than is available in the inventory
             the vending machine gives them up to that amount and then makes the
             option no longer available. After the user quits after requesting
             all the items he/she wants, the total cost is determined with taxes
             and the user is asked to pay. Then the program ends
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

  /////////
  // Initialization of Option One Variables
  // (Name, Cost, Amount in Stock inventory)
  /////////
  const string OPTIONONE = "Ginko Root";
  const float COSTONE = 4.50;
  short inventoryOne = 5;

  /////////
  // Initialization of Option Two Variables
  // (Name, Cost, Amount in Stock inventory)
  /////////
  const string OPTIONTWO = "Mandrake Root";
  const float COSTTWO = 1.23;
  short inventoryTwo = 4;

  /////////
  // Initialization of Option Three Variables
  // (Name, Cost, Amount in Stock inventory)
  /////////
  const string OPTIONTHREE = "Ginseng Root";
  const float COSTTHREE = 2.39;
  short inventoryThree = 9;

  /////////
  // Initialization of Option Four Variables
  // (Name, Cost, Amount in Stock inventory)
  /////////
  const string OPTIONFOUR = "Square Root";
  const float COSTFOUR = 99.98;
  short inventoryFour = 11;

  /////////
  // Initialization of Option Five Variables
  // (Name, Cost, Amount in Stock inventory)
  /////////
  const string OPTIONFIVE = "Vitamin R Root";
  const float COSTFIVE = 0.78;
  short inventoryFive = 8;

  /////////
  // Initialization of Option Six Variables
  // (Name)
  /////////
  const string OPTIONSIX = "Quit";

  /////////
  // Initialization of user input Variables
  // (First name of user, the item the user wants, and the quantity user wants)
  /////////
  string firstName = "";
  short userSelection = 0;
  short userAmountInput = 0;

  /////////
  // Initialization of 'total' variables
  // (Total payed, total owned, and total change all calculated throughout
  // program)
  /////////
  float totalPayed = 0;
  float totalOwed = 0;
  float totalChange = 0;

  /////////
  // Vending Machines welcome message, catalog display, and user name input
  /////////
  cout << "Hello Random User! Please insert your first name: ";
  cin >> firstName;
  cout << "Welcome " << firstName << "! Let me give you the catalog." << endl
       << endl;

  /////////
  // Main loop for the vending machine. Keeps the user within the loop
  // until the user enters the value 6 for quit. Also validates all inputs
  // for malformation improper syntax
  /////////
  do
  {
    /////////
    // Vending machine main menu output, changes depending on the amount of
    // inventory available
    /////////
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

    /////////
    // User selects which item he wanted from the vending machine
    /////////
    cin >> userSelection;

    /////////
    // Validates the input for range errors
    /////////
    if( userSelection >= 0 && userSelection <= 6)
    {
      /////////
      // Validates the input if the inventory is out of stock for item chosen
      // NOTE: does not validate six because it will automatically not use
      //       switch statement and exit loop
      /////////
      if((userSelection == 1 && inventoryOne > 0) ||
         (userSelection == 2 && inventoryTwo > 0) ||
         (userSelection == 3 && inventoryThree > 0) ||
         (userSelection == 4 && inventoryFour > 0) ||
         (userSelection == 5 && inventoryFive > 0))
      {
        /////////
        // User input for quantity they wish of item chosen above
        /////////
        cout << "How many would you like to order: ";
        cin >> userAmountInput;

        /////////
        // Input validation for if the input its a postive amount wanted
        /////////
        if (userAmountInput >= 0)
        {
          /////////
          // Switch statement which determines the item inventory the user
          // inputted to make sure the right amount of cost is calculated
          /////////
          switch(userSelection)
          {
            /////////
            // Null case: if user changes his/her mind
            /////////
            case 0:
              break;

            /////////
            // Option One-Five case:
            // If-else condition:
            // 1) If: Determines if the user wants more than the inventory and
            //    correctly handles
            // 2) Else: calculates cost of ordered quantity and removes the
            //    quantity from inventory
            /////////
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

            /////////
            // See Case 1 Description
            /////////
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

            /////////
            // See Case 1 Description
            /////////
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

            /////////
            // See Case 1 Description
            /////////
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

            /////////
            // See Case 1 Description
            /////////
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
              /////////
              // No  need for case 6 because already validated for
              //
              // No need for default cause due to all other exception validated
              // for in header
              /////////
          }
        }
        else //Error handling for if user inputs < 0 for quantity
        {
          cout << "  [ERROR] You cannot order that little! TRY AGAIN."
               << endl << endl;
        }
      }
      else //Error handling for userInput > amountOfChosenInventory
      {
        cout << "  [ERROR] It says NO LONGER AVAILABLE! Try again."
             << endl << endl;
      }
    }
    else //Error handling for outside range
    {
      cout << "  [ERROR] That doesnt exsist here! Try again." << endl << endl;
    }

  }
  while(userSelection != 6); //End of main loop

  /////////
  // Calcuation of tax after all items ordered
  /////////
  totalOwed *= 1.16;

  /////////
  // Secondary loop to make sure that the user pays the amount he owes
  // also calculates the dollar amount of change the person receives
  /////////
  do
  {
    cout << "Time to pay up! You owe: " << totalOwed << " in cash!"<< endl
         << "How much money would you like to pay: ";
    cin >> totalPayed;
    totalChange = totalPayed - totalOwed;
    (totalChange < 0) ? cout << "\n[Error] " : cout << "\n";
  }
  while(totalChange < 0);

  /////////
  // Correct output handling if the user should receive change
  /////////
  if(totalChange == 0)
  {
    cout << "Thank you for paying! Until next time!" << endl;
  }
  else
  {
    cout << "Thank you for paying! Now giving you " << totalChange
         << " dollars. Goodbye!" << endl;
  }

  /////////
  // Obligatory End
  /////////
  return 0;
}
