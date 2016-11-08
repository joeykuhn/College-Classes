/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/10/12
Description: This program allows the user to input a Movie and lead actor,
             allows them to rate this movie based on the criteria of acting
             ability of lead actor, appearance of lead actor, popularity of
             lead actor, freshness of plot, and popularity. The program then
             takes these values the user inputs and creates two averages:
             a plot rating average and a lead actor rating average.
             The program then takes these two averages and averages
             them together to create an overall rating average and outputs
             the three different averages for each movie.
*/

#ifndef HEADER
#define HEADER

#include<iostream>
using namespace std;

//////////
// Declaration of the struct type Movie which contains the biographical data
// of title and lead actor name as well as the ratings which the user inputs and
// averages of those ratings.
//////////
struct Movie
{
  string title;
  string leadActor;
  float overallRating;
  int actorRating;
  int plotRating;
  int actorParam1, actorParam2, actorParam3;
  int plotParam1,plotParam2;
};

//////////
// Pre: param1 should be the string "overall", "actor", or "plot"
//      param2 should be the movie title
//      param3 should be between 0 and 10
// Post: None
// Function: This function handles the formatting and output of
//           the different ratings for actor rating,
//           plot rating, and overall rating.
//////////
template <typename T1, typename T2, typename T3>
void printRatings (const T1 param1, const T2 param2, const T3 param3)
{
  cout << param1 << " rating for " << param2 << " is: " << param3 << "/10."
       << endl;

  return;
}

//////////
// Pre: Should be a structure with 10 defined attributes.
//      Types listed in 'struct Movie'.
// Post: Sets the user enteries into each of the attributes of the struct.
// Function: This function allows for the proper formatting and user input
//           of the data to be assigned into the Movie struct.
//////////
void getInput(Movie &movie);

//////////
// Pre: the actorParams should be between 0 and 10.
// Post: returns the rounded positive average of the three parameters.
// Function: This function takes the three parameters, averages them together
//           and rounds the result of that average. Then, it returns that
//           rounded value.
//////////
int calcRating(const int actorParam1, const int actorParam2, const int actorParam3);

//////////
// Pre: the plotParams should be between 0 and 10.
// Post: returns the rounded positive average of the two parameters.
// Function: This function takes the two parameters, averages them together
//           and rounds the result of that average. Then, it returns that
//           rounded value.
//////////
int calcRating(const int plotParam1, const int plotParam2);

//////////
// Pre: the movie should be a struct with 10 defined attributes.
//      actorRating and plotRating should both be between 0 and 10.
// Post: Changes the overall rating attribute of the movie struct through
//       pass-by-reference
// Function: This this function takes the two attributes of actorRating and
//           plotRating, averages them, rounds the result, and then returns that
//           value in the overallRating attribute of the Movie struct
//////////
void setOverallRating(Movie &movie);

//////////
// Pre: the movie should be a struct with 10 defined attributes.
//      overallRating, actorRating, and plotRating should all be defined
//      attributes between 0 and 10
// Post: None
// Function: This function takes the values of overallRating, actorRating, and
//           plotRating for each movie, formats them, and prints them out to
//           the user
//////////
void printOutputs(const Movie &movie1, const Movie &movie2);

//////////
// Pre: None
// Post: Returns a value that is inclusively between the upper and lower bound
// Function: This function validates whether the user input is between the
//           upper and lower bounds. If it is, it returns the user's input.
//           otherwise it prints and error and forces them to reinput the value.
//////////
int validIntInput(int lowerBound, int upperBound);

#endif
