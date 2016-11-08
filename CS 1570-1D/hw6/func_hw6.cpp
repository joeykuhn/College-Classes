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

//////////
// Tax calculation
//////////
const int TAX = 16;

void greeting()
{
  cout << endl << "Welcone to the Roots 'n Stuff Vending Machine!" << endl;
  return;
}

string getName()
{
  string nameStorage = "";
  cout << "Please enter your name (no spaces): ";
  cin >> nameStorage;
  cout << "Glad to meet you, " << nameStorage << "!" << endl;
  return nameStorage;
}

void printMenu( const OptionData Roots[], const string quitMessage)
{
  cout << endl
       << "===========================" << endl
       << "-      Roots 'n Stuff     -" << endl
       << "===========================" << endl
       // Option one formatting
       << "1) " << Roots[0].name << "      ($" << Roots[0].cost << ")"
       << " " << (Roots[0].stock > 0 ? "" : "NO LONGER AVAILABLE") << endl

       // Option two formatting
       << "2) " << Roots[1].name << "   ($" << Roots[1].cost << ")" << " "
       << (Roots[1].stock > 0 ? "" : "NO LONGER AVAILABLE") << endl

       //Option three formatting
       << "3) " << Roots[2].name << "    ($" << Roots[2].cost << ")"
       << " "
       << (Roots[2].stock > 0 ? "" : "NO LONGER AVAILABLE") << endl

       //Option four formatting
       << "4) " << Roots[3].name << "    ($" << Roots[3].cost << ")" << " "
       << (Roots[3].stock > 0 ? "" : "NO LONGER AVAILABLE") << endl

       //Option five formatting
       << "5) " << Roots[4].name << "  ($" << Roots[4].cost << ")" << " "
       << (Roots[4].stock > 0 ? "" : "NO LONGER AVAILABLE") << endl

       //Option six formatting
       << "6) " << quitMessage << endl
       << "===========================" << endl << endl;

  return;
}

void signOff(float totalChange)
{
  if(totalChange == 0)
  {
    cout << "Thank you for paying! Until next time!" << endl;
  }
  else
  {
    cout << "Thank you for paying! Now giving you " << totalChange
         << " dollars.";
  }

  cout << endl << "Thank you for shopping at Roots 'n Stuff!"
       << " See you later." << endl;

  return;
}

bool inclusiveRangeValidation(const int lowerBound, const int upperBound,
                              const int input, const int exception)
{
  if(input >= lowerBound && input <= upperBound)
  {
    if(input == exception)
    {
      return(false);
    }
    return(true);
  }
  else
  {
    cout << "[Error] READ THE MENU! That doesnt exsist here." << endl << endl;
    return(false);
  }
  cout << "[Error] An error occured in inclusiveRangeValdiation."
       << endl << endl;
  return false;
}

bool stockValidation(const int userSelection, const OptionData Roots[])
{
  if(userSelection >= 0 && userSelection <= 4)
  {
    if(Roots[userSelection].stock > 0)
    {
      return(true);
    }
    else
    {
      cout << "[Error] We are OUT OF STOCK for that item." << endl << endl;
      return(false);
    }
  }

  return(false);
}

int my_rand(const int lowerBound, const int upperBound)
{
  return((rand()%((upperBound-lowerBound)+1)) + lowerBound);
}

void parseUserQuantity(const int currentStock, int &userAmountInput)
{
  if(userAmountInput > currentStock)
  {
    cout << "[Vending Machine] I can only give you " << currentStock << "."
         << endl;
    userAmountInput = currentStock;
  }
}

float calculateCost(const int numberToBuy, const int optionCost)
{
    return(optionCost * numberToBuy);
}

float calculateTax(const int subTotal)
{
  if(subTotal < 100)
  {
    return(static_cast<float>(subTotal) * .5);
  }
  else if(subTotal <= 300)
  {
    return(static_cast<float>(subTotal) * .27);
  }
  else if(subTotal > 300)
  {
    return(static_cast<float>(subTotal) * .02);
  }
  else
  {
    cout << "[ERROR] An error occured in calculateTax()." << endl << endl;
    return 0;
  }
}

float transactionHandler(const float totalOwed)
{
  float totalPayed = 0;
  float totalChange = 0;
  do
  {
    cout << "Time to pay up! You owe: " << totalOwed << " in cash!"<< endl
         << "How much money would you like to pay: ";
    cin >> totalPayed;
    totalChange = totalPayed - totalOwed;
    (totalChange < 0) ? cout << "\n[Error] " : cout << "\n";
  }
  while(totalChange < 0);

  return(totalChange);
}

void round(float &input)
{
  input += .005;
  return;
}

void randUserOption(int &userOptionInput, const string sassMessages[],
                    const OptionData Roots[])
{
  //////////
  // Account for array indexes
  //////////

  int randUsrSelect = (my_rand(0,6)); // This is between 0-6 because my options
  int randUsrOutput = (my_rand(1,7)); // are 0-4 so 5 is quit and 6 is the +1
  userOptionInput -= 1;

  if(randUsrSelect <= 5)
  {
    if(userOptionInput == randUsrSelect)
    {
      cout << sassMessages[0] << endl;
    }
    else if(randUsrSelect == 5)
    {
      userOptionInput = randUsrSelect;
    }
    else
    {
      userOptionInput = (randUsrSelect);
      cout << sassMessages[randUsrOutput] << Roots[randUsrSelect].name << endl;
    }
  }
  else
  {
    userOptionInput = randUsrSelect;
  }

  return;
}

void randUserAmount(int &userAmountInput, const string amountMessages[])
{
  int randUsrAmount = my_rand(1, 2*userAmountInput+1);

  if (randUsrAmount == userAmountInput)
  {
    userAmountInput = randUsrAmount;
    cout << amountMessages[0] << endl;
  }
  else if(randUsrAmount > userAmountInput)
  {
    userAmountInput = randUsrAmount;
    cout << amountMessages[2] << userAmountInput << endl;
  }
  else if(randUsrAmount < userAmountInput)
  {
    userAmountInput = randUsrAmount;
    cout << amountMessages[1] << userAmountInput << endl;
  }


  return;
}
