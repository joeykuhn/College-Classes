/*
Programmer: Kevin Schoonover
Instructor: Dr. Leopold
Section: 1D
Date: 10/03/16
Description: This program usage the user's damage to the environment and
             calculates their total 'Guilt value' in order to guilt the user
             into action. In order to do this, the program measures four
             different ascepts: Wasteful Consumption, Public Trasnit Usage,
             Industrial Complicity, and Methane Production. Then, with these
             values its calculates the users total guilt value using a formula
             and summation. Then, it returns the value and a signoff.
*/

///////////
// ¯\_(ツ)_/¯
///////////
#include <iostream>
using namespace std;

// ********** CONST Initialization *********
  //////////
  // Variables which define the range for wastefulConsumption function
  /////////

  const short MIN_WASTE = 1;
  const short MAX_WASTE = 100;

  /////////
  // Variables which define the range for the publicTransiteUsage function
  /////////
  const short MIN_MILES = 1;
  const short MAX_MILES = 250;

  /////////
  // Burn's Constant as used in industrialComplicity function
  ////////
  const short BURNS_CONSTANT = 570;

  //////////
  // Variable Initialization for the range of age used in Industrial Complicity
  /////////
  const short MIN_AGE = 0;
  const short MAX_AGE = 100;

  //////////
  // Variable Initialization for the arguments for modifyValue used to modify
  // option one.
  //////////
  const float ONE_MULTIPLIER = 1.5;
  const short ONE_OFFSET = 6;

  //////////
  // Variable Initialization for the arguments for modifyValue used to modify
  // option two.
  //////////
  const short TWO_MULITPLIER = -2;
  const short TWO_OFFSET = 1;

// ********** Global Variable Initialization **********

  //////////
  // Variables for the menu names
  //////////
  const string OPTION_ONE = "Wasteful (food) consumption";
  const string OPTION_TWO = "Public Transit Usage";
  const string OPTION_THREE = "Industrial Complicity";
  const string OPTION_FOUR = "Farm-related Methane Production";
  const string OPTION_FIVE = "Compute GUILT value";



// ********** Function Prototypes **********

  //////////
  // @Pre: None
  // @Post: None
  // @Purpose: Display the initial welcome message to the user
  //////////
  void welcomeMessage();

  //////////
  // @Pre: None
  // @Post: None
  // @Purpose: Print the menu the user has the ability to pick from with
  //           options defined in the Global Variable Initialization.
  /////////
  void printCarbonMenu();

  /////////
  // @Pre: Requires completetion of Options 1-4 to attain guiltValue
  // @Post: None
  // @Purpose: Prints the signoff message which contains the users total
  //           guilt number calculated throughout the program
  ////////
  void signoff(const float guiltValue);

  //////////
  // @Pre: None
  // @Post: Whole number output
  // @Purpose: Calculates the Wasteful Consumption which the users incurs
  //           throughout their week by asking them the question
  //           "How much food goes wasted per week" and validates a whole
  //           number output.
  /////////
  float wastefulConsumption();

  /////////
  // @Pre: Must be between the range MIN_WASTE and MAX_WASTE
  // @Post: None
  // @Purpose: Determines whether or not the user uses publkic transportation
  //           and if so, determines the amount of miles that they use it.
  //           Returns the int of the hours the user utilizing public transport.
  /////////
  int publicTransitUsage();

  /////////
  // @Pre: Must be between the range MIN_MILES and MAX_MILES
  // @Post: None
  // @Purpose: Calculates the Industrial Complicity of the user and then
  //           returns that values as an integer. In oder to determine the
  //           Industrial Complicity, the program prompts the user if they
  //           are Mr. Burns. If they are, the function returns the burns
  //           constant. Otherwise it asks if they are related to Mr. burns
  //           If they are, it returns half of the burns constant. Otherwise
  //           It prompts them for age and returns that values.
  ////////
  int industrialComplicity();

  /////////
  // @Pre: Must have completed option one to get argument.
  // @Post: None
  // @Purpose: Determines the amount of metahen a user produces and outputs
  //           the number. The function determines this by asking the user
  //           how many whole pigs the user's father at that week and
  //           runs it through a formula to return the value.
  ////////
  float methaneProduction( const float OUTPUT_WASTEFULCONSUMPTION );

  ///////////
  // @Pre: Must hve completed all options in the menu.
  // @Post: None
  // @Purpose: Adds all the values gathered throughout the program
  //           and returns the summation.
  //////////
  float guiltComputation( const float WASTE, const float TRANSIT,
                          const float COMPLICITY, const float METHANE);

  //////////
  // @Pre: None
  // @Post: None
  // @Purpose: Multiplys the value argument by the multiplier argument then
  //           adds the offset finally returning the value.
  //////////
  float modifyValue( const float VALUE, const float MULTIPLIER, const float OFFSET);


// ********** Function Definitions **********
void welcomeMessage()
{
  cout << "Welcome to Lisa's Carbon Footprint Survey, prepare to"
       << " learn your damage. :)" << endl;

  return;
}

void printCarbonMenu()
{
  cout << "\tCarbon Footprint Survey" << endl
       << "\t-----------------------" << endl
       << " 1. " << OPTION_ONE << endl
       << " 2. " << OPTION_TWO << endl
       << " 3. " << OPTION_THREE << endl
       << " 4. " << OPTION_FOUR << endl
       << " 5. " << OPTION_FIVE << endl;

  return;
}

void signoff(const float guiltValue)
{
  cout << "I am extremely proud of you, great job getting " << guiltValue
       << " guilt value. Fantastic! Goodbye." << endl;

  return;
}

float wastefulConsumption()
{
  //////////
  // Temporary float for holding the waste inputted by the user
  //////////
  float outputWaste = 0;

  do
  {
  cout << "How much food goes wasted in your house?( " << MIN_WASTE
       << " - " << MAX_WASTE << " )" << endl;

  cin >> outputWaste;
  }
  while(outputWaste > MAX_WASTE || outputWaste < MIN_WASTE);

  return outputWaste;
}

int publicTransitUsage()
{
  //////////
  // Temporary char for holding the user input of public transit
  /////////
  char useTransit;

  /////////
  // Temporary int for holding the user input for miles per day
  /////////
  int milesPerDay = 0;

  do
  {
    cout << "Do you use public transit of any kind? (y/n): ";

    cin >> useTransit;
  }
  while(useTransit != 'y' && useTransit != 'n');

  if(useTransit == 'y')
  {

    do
    {
      cout << "How many miles per day? ( "
           << MIN_MILES << " - " << MAX_MILES << " )" << endl;

      cin >> milesPerDay;
    }
    while(milesPerDay > MAX_MILES || milesPerDay < MIN_MILES);

    return milesPerDay;
  }
  else
  {
    return 0;
  }
}

int industrialComplicity()
{
  //////////
  // Local Variable Initialization for temporary storing values necessary for
  // function. isBurns checks user input for Are you Burns? against the
  // acceptable values. isRelated checks again acceptables values for next
  // question. Age stores the value for what the user enters as age and
  // validates it.
  //////////
  string isBurns;
  string isRelated;
  int age = 0;

  do
  {
    cout << "Are you Mr. Burns (y/n): ";
    cin >> isBurns;
    cout << endl;
  }
  while(isBurns != "y" && isBurns != "n");

  if(isBurns == "y")
  {
    return BURNS_CONSTANT;
  }
  else
  {
    do
    {
      cout << "Are you related to Mr. Burns (y/n): ";
      cin >> isRelated;
    }
    while(isRelated != "y" && isRelated != "n");

    if(isRelated == "y")
    {
      return (BURNS_CONSTANT / 2);
    }
    else
    {
      do
      {
        cout << "How old are you (yrs): ";
	      cin >> age;
      }
      while(age > MAX_AGE || age < MIN_AGE);

      return age;
    }
  }
}

float methaneProduction( float outputWasteful )
{
  /////////
  // Temporary int for storing the user input to how many pigs father ate
  /////////
  int pigsEaten = 0;

  do
  {
    cout << "How many whole pigs has your father ate this week: ";

    cin >> pigsEaten;
  }
  while(pigsEaten < 0);

  return(outputWasteful * (pigsEaten * pigsEaten) + (3 * pigsEaten + 5));
}

float guiltComputation( float waste, float transit,
                        float complicity, float methane)
{
  return(waste + transit + complicity + methane);
}

float modifyValue( const float value, const float multiplier, const float offset)
{
  return(value * multiplier + offset);
}


// ********** Main Function **********

int main()
{
  //////////
  // Variable Initialization to determine whether a user has sucessfully
  // completeled the different options.
  //////////
  bool hasSelectedOne = false;
  bool hasSelectedTwo = false;
  bool hasSelectedThree = false;
  bool hasSelectedFour = false;
  bool hasSelectedFive = false;

  //////////
  //  Variable Initialization which stores the outputs of each of the functions
  //  in order to be added in guiltComputation and modified.
  //////////
  float output_WastefulConsumption = 0;
  int output_publicTransit = 0;
  int output_industrialComplicity = 0;
  float output_methane = 0;
  float totalGuilt = 0;

  //////////
  //  Variable Initialization for the variable which holds the user's menu
  //  choice
  //////////
  int userDecision = 0;


  //////////
  // See function prototype
  //////////
  welcomeMessage();

  do
  {
    //////////
    //  See function prototype
    //////////
    printCarbonMenu();

    //////////
    //  User Input
    //////////
    cout << endl << "What would you like to select: ";

    cin >> userDecision;

    cout << endl;

    //////////
    // Switch statement to cycle through the different menu options and call
    // the correct function
    //////////
    switch(userDecision)
    {

      //////////
      // Handling for the Wasteful Consumption option.
      //////////
      case 1:
      {

        //////////
        // See if user has already selected option
        //////////
        if(!hasSelectedOne)
        {
          //////////
          // Function handling, success message, and future event handling.
          //////////
          output_WastefulConsumption = wastefulConsumption();
  	      cout << "[Success] Finished with Option One!"
  	           << " Thank you. Move to the next one." << endl << endl;

          hasSelectedOne = true;
        }

        //////////
        // Error handling
        //////////
        else
        {
          cout << "[Error] You have already selected this number,"
               << " please choose a different number." << endl << endl;
        }

        break;
      }

      //////////
      // Handling for the Public Trasnit Usage option
      //////////
      case 2:
      {
        //////////
        // Follows same format as case 1
        //////////
        if(!hasSelectedTwo)
        {
          output_publicTransit = publicTransitUsage();
  	      cout << "[Success] Finished with Option Two!"
  	      << " Thank you. Move to the next one." << endl << endl;

  	      hasSelectedTwo = true;
        }
        else
        {
          cout << "[Error] You have already selected this number,"
               << " please choose a different number." << endl << endl;
        }
	      break;
      }

      //////////
      // Handling for the Industrial Complicity option
      //////////
      case 3:
      {
        //////////
        // Follows same format as case 1
        //////////
        if(!hasSelectedThree)
        {
          output_industrialComplicity = industrialComplicity();
          cout << "[Success] Finished with Option Three!"
  	      << " Thank you. Move to the next one." << endl << endl;

          hasSelectedThree = true;
        }
        else
        {
          cout << "[Error] You have already selected this number,"
               << " please choose a different number." << endl << endl;
        }
        break;
      }

      //////////
      // Handling for the Methane Production Option
      /////////
      case 4:
      {
        //////////
        // Follows same format as case 1
        // Except also checks if option one has been completed
        //////////
        if(hasSelectedOne && !hasSelectedFour)
	      {
          output_methane = methaneProduction(output_WastefulConsumption);
          cout << "[Success] Finished with Option Four!"
	             << " Thank you. Move to the next one." << endl << endl;
	        hasSelectedFour = true;
	      }
	      else
	      {
	        cout << "[Error] Option 4 currently not available. You have"
               << " either already selected it or have not chosen Option"
               << " 1."<< endl;
	      }

	      break;
      }

      //////////
      // Handling for the Guilt Computation option
      //////////
      case 5:
      {
        //////////
        // Checks to make sure all options have been selected
        /////////
        if( hasSelectedOne && hasSelectedTwo &&
            hasSelectedThree && hasSelectedFour)
	      {

          //////////
          // Calculates total guilt with returns of modify Value and outputs
          // NOTICE: HORRIBLE INDENTATION DUE TO 80 CHAR STANDARDS, SORRY.
          /////////
	        totalGuilt = guiltComputation(
            modifyValue(output_WastefulConsumption, ONE_MULTIPLIER, ONE_OFFSET),
            modifyValue(output_publicTransit, TWO_MULITPLIER, TWO_OFFSET),
            output_industrialComplicity,
            output_methane);

	        hasSelectedFive = true;
	      }

        //////////
        // Error handling
        /////////
	      else
	      {
	        cout << "[Error] Please Select all other options before"
               << " selecting option 5." << endl;
        }

	      break;
      }

      //////////
      // Error handling for if the user chose something that is not an option
      /////////
      default:
      {
        cout << "[Error] Not a valid option. Try Again." << endl;
      }
    }
  }while(userDecision != 5 ||  !hasSelectedFive);

  //////////
  // End of function that displays the total guilt
  /////////
  signoff(totalGuilt);

  //////////
  // Obligatory end
  // ¯\_(ツ)_/¯
  /////////
  return 0;
  //////////
  // ¯\_(ツ)_/¯
  //////////
}
