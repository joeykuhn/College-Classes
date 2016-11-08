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


#ifndef GREET_H
#define GREET_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//////////
// Array initializatation for the array which contains all the messages which
// will be outputted by the randUsrOption() function in respoonse to a userInput
// change.
//////////
const string optionMessages[8] = {"Fine! ... but you're gonna be sorry.",
"No, you really want ",
"As my uncle Hal would say, \"I can\'t do that for you, Dave.\" You want ",
"Only a loooooser would want THAT.  Try this instead: ",
"WRONG!  I'm sure you meant to pick ", "PPpfffffttt.  I think you need ",
"Only idiots choose that.  Better to have some ",
"Tss, you must be Homer!  Only Homer would want that.  Lisa's preference is "};

//////////
// Array initializatation for the array which contains all the messages which
// will be outputted by the randUsrAmount() function in respoonse to a
// userAmountInput change.
//////////
const string amountMessages[3] = {"I can do that ... ",
"That's waayyy too much for you. You want ", "Naw naw naw, you need  "
};


//////////
// Struct initializatation which will contain all of the data for each of the
// five different roots whch need to be defined in the main.
// Including: Name of the Root, the cost of the root, and the amount of stock
//            remaining of the root.
//////////
struct OptionData
{
  const string name;
  const float cost;
  short stock;
};

//////////
// @Pre: None
// @Post: Oututs the greeting message to the user
// @Description: This function simply greets the user to the vending machine.
//////////
void greeting();

//////////
// @Pre: User must inputs a non-spaced string into the cin statement
// @Post: The function prints a personalized with the users name and returns
//        the name.
// @Description: This function takes the users first name, stores it into a
//               temporary variable, and returns that name to the function after
//               printing a personalized greeting.
//////////
string getName();

//////////
// @Pre: Requires the Roots array to have five elements with name, cost, and
//       stock elements defined within each element (See struct OptionData def)
// @Post: Prints out the stock menu for the user and includes 'NO LONGER
//        AVAILABLE' if the stock of that item is zero.
// @Description: This function prints out a menu displaying the name, cost,
//               and stock of each of the different roots.
//////////
void printMenu( const OptionData Roots[], const string quitMessage);

//////////
// @Pre: totalChange must be defined and greater than zero.
// @Post: The function will print out a goobye message which displays the amount
//        of  change the user will receive if any.
// @Description: The function takes the total change caluclated earlier in the
//               program and outputs a goodbye message which includes the
//               change the user would receive if any.
//////////
void signOff(float totalChange);

//////////
// @Pre: numberToBuy and optionCost must be greater than zero
// @Post: returns the quotient of numberToBuy and optionCost
// @Description: This function takes the cost of whatever the user is trying to
//               to buy and multiplies it by the amount they wish to by,
//               returning the total cost that they bought.
//////////
float calculateCost(const int numberToBuy, const int optionCost);

//////////
// @Pre: currentStock and userAmountInput must both be defined.
// @Post: If the userAmountInput is greater than the stock, the function
//        will change userAmountInput so that userAmountInput will be equal
//        to the stock
// @Description: This function parses the userAmountInput so that it can never
//               be greater than the stock of the item the user wishes to buy
//               to make sure stock is never negative when bought.
//////////
void parseUserQuantity(const int currentStock, int &userAmountInput);

//////////
// @Pre: LowerBound must be less than upperBound.
// @Post: The function returns a random number between lowerBound
//        and upperBound.
// @Description: The function takes in lowerBound and upperBound and then
//               returns the number that is between those two parameters.
//////////
int my_rand(const int lowerBound, const int upperBound);

//////////
// @Pre: subTotal should be greater than 0
// @Post: The function returns the tax dependent on the the subtotal entered
//        into it.
// @Description: This function takes the subTotal and checks it against the
//               tax code given by the Simposons reality. Then returns the
//               amount of tax the subTotal should have.
//////////
float calculateTax(const int subTotal);

//////////
// @Pre: Input must be defined.
// @Post: Will return the rounded input pass by reference.
// @Description: This function takes an input, adds .005 to it, and returns that
//               value by reference to input inorder to properly round it.
//////////
void round(float &input);

 //////////
 // @Pre: totalOwed should be greater than zero.
 // @Post: This function output the amount of mone
 // @Description:
 //////////
float transactionHandler(float totalOwed);

//////////
// @Pre: lowerBound must be less than upperBound, exception should be within the
//       range.
// @Post: The function returns true if the input is inbetween lowerBound and
//        upperBound and false if the input is equal to the exception or not in
//        the range.
// @Description: The function takes the input, lowerBound, and upperBound
//               and validates if the input is greater than or equal to
//               the lowerBound. If it is, the funciton then checks if the
//               input is equal to the exception. If it is it returns false,
//               if it is not, it returns true. If it is not betweent the
//               boundry, it returns false.
//////////
bool inclusiveRangeValidation(const int lowerBound, const int upperBound,
                              const int input, const int exception);

//////////
// @Pre: The function requires sassMessages to be an array with
//       8 defined values and Roots must be an array with 5 defined values.
// @Post: the value returns the random userOptionInput which it generates by
//        reference and also prints a random output message.
// @Description: This function takes the userInput and randomly generates a
//               value between 1 and 7, with this random number, it generates a
//               random output message depending on if the random number is
//               equal to the input number. The userOptionInput is also
//               sets to the random number generated.
//////////
void randUserOption(int &userOptionInput, const string sassMessages[],
                    const OptionData Roots[]);

//////////
// @Pre: This function requires amountMessages to an array with three elements.
// @Post: This function changes userAmountInput by reference to a random number
//        between one and the input mulitplied by two plus one and outputs a
//        message based on the original input compared to the random number.
// @Description: This function generates a random number from one to two times
//               the userAmountInput plus one and outputs and changes
//               userAmountInput by reference to that number. Moreover,
//               the function outputs a message depending on if the random
//               number is >,<,== the userInput.
//////////
void randUserAmount(int &userAmountInput,
                   const string amountMessages[]);

//////////
// @Pre: This function requires amountMessages to an array with an index that
//       exsists at userSelect and userSelection must be between 0 and 4.
// @Post: Returns true or false depending on if there is stock remaining for the
//        specific root being referenced.
// @Description: This function takes in the userSelect and Roots in order to
//               determine whether the specific root that the user select
//               has a stock that is greater than 0.
//////////
bool stockValidation(const int userSelction, const OptionData Roots[]);

#endif
