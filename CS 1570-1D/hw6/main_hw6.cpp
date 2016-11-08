/*
Programmer: Kevin Schoonover
Instructor: Dr. Leopold
Section: 1D
Date: 10/14/16
Description: This code is a vending machine which outputs a main catalog menu to
             the user to determine what they want. After the user states which
             item they want, the program randomly decides another value for the
             user. They are able to choose how many of the item they
             want. After they choose how many they want, the program randomly
             changes how many they want to buy between 1 and two plus one times
             the number they want.If the user requests more than is available in
             the inventory the vending machine gives them up to that amount and
             then makes the option no longer available. After the user quits
             after requesting all the items he/she wants, the total cost is
             determined with taxes and the user is asked to pay. Then the
             program ends.
*/

#include "header_hw6.h"

int main()
{

  //////////
  // Formatting for the menu and holding the data for all of the Root
  // operations.
  //////////
  OptionData Roots[5] = {
    {"Ginko Root", 4.50, 5}, {"Mandrake Root", 1.23,4},
    { "Ginseng Root", 2.39, 9}, {"Square Root", 99.98, 11},
    {"Vitamin R Root", 0.78, 8}};
  const string quitMessage = "Quit";

  /////////
  // Initialization of user input Variables
  // (First name of user, the item the user wants, and the quantity user wants)
  /////////
  string name = "";
  int userSelection = 0;
  int userAmountInput = 0;

  /////////
  // Initialization of 'total' variables
  // (Total payed, total owned, and total change all calculated throughout
  // program)
  /////////
  float totalOwed = 0;
  float totalChange = 0;
  float totalTax = 0;
  float totalOwedAfterTax = 0;

  //////////
  // "Magic Code"
  //////////
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  srand(time(NULL));

  //////////
  // Greeting the user and gathering their name for output
  //////////
  greeting();
  name = getName();

  //////////
  // Setting up the do-while to make the function continue until the user
  // wishes to stop by putting in 6. The do-while ends at 6 because the function
  // subtracts one from the userSelection in order to make the array indexs work
  //////////
  do
  {
    //////////
    // Prints menu for the user to pick from
    //////////
    printMenu(Roots, quitMessage);

    //////////
    // Getting user's input
    //////////
    cout << "Please select an option on the list: ";
    cin >> userSelection;

    //////////
    // Randomizing the user's input and outputing the change message
    //////////
    randUserOption(userSelection, optionMessages , Roots);

    //////////
    // Check to make sure the user is within the menu range(with account for
    // the index) and the
    //////////
    if(inclusiveRangeValidation(0,5, userSelection, 5)
       && stockValidation(userSelection, Roots))
    {
      //////////
      // Get user input for amount
      //////////
      cout << "How many would you like to order: ";
      cin >> userAmountInput;

      /////////
      // Input validation for if the input its a postive amount wanted
      /////////
      if (userAmountInput >= 0)
      {
        //////////
        // Calculate random quanty and return that value
        //////////
        randUserAmount(userAmountInput, amountMessages);
        //////////
        // Make sure the user does not try to buy more than is in stock
        //////////
        parseUserQuantity(Roots[userSelection].stock, userAmountInput);
        //////////
        // Remove the stock from the inventory so that you cannot buy infintely
        //////////
        Roots[userSelection].stock -= userAmountInput;
        //////////
        // Calculate the money to buy the amount thet user wants and add it
        // to the total
        //////////
        totalOwed += calculateCost(userAmountInput, Roots[userSelection].cost);
      }
    }
  } while(userSelection != 5);

  //////////
  // Calculating tax and adding it to the totalOwedAfterTax for complete tax
  //////////
  totalTax = calculateTax(totalOwed);
  totalOwedAfterTax = totalTax + totalOwed;

  //////////
  // Handling the transaction and getting the money from the user while
  // returning change
  //////////
  totalChange = transactionHandler(totalOwedAfterTax);

  //////////
  // Sign off and returns the change if they should receive any
  //////////
  signOff(totalChange);

  //////////
  // Obligatory End
  //////////
  return 0;
}
