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
#include "lab8_header.h"

int main()
{
  //////////
  // Initial struct declartion for movie data storage.
  //////////
  Movie movie1 = {" ", " ", 0, 0, 0, 0, 0, 0, 0, 0};
  Movie movie2 = {" ", " ", 0, 0, 0, 0, 0, 0, 0, 0};

  //////////
  // Input for Movie 1 values.
  //////////
  cout << "Enter Movie 1 details" << endl;
  getInput(movie1);

  //////////
  // Input for Movie 2 values.
  //////////
  cout << "Enter Movie 2 details" << endl;
  getInput(movie2);


  //////////
  // Calculation of the average actor rating.
  //////////
  movie1.actorRating = calcRating(movie1.actorParam1,
                                  movie1.actorParam2,
                                  movie1.actorParam3);
  movie2.actorRating = calcRating(movie2.actorParam1,
                                  movie2.actorParam2,
                                  movie2.actorParam3);

  //////////
  // Calculation of the average plot rating
  //////////
  movie1.plotRating = calcRating(movie1.plotParam1, movie1.plotParam2);
  movie2.plotRating = calcRating(movie2.plotParam1, movie2.plotParam2);

  //////////
  // Calculation of the average overall rating.
  //////////
  setOverallRating(movie1);
  setOverallRating(movie2);

  //////////
  // Proper formating and printing of the averagse
  //////////
  printOutputs(movie1, movie2);

  //////////
  // Obligatory End ¯\_(ツ)_/¯
  //////////
  return 0;
}
