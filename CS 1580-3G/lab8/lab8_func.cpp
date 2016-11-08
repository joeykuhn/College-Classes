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
int validIntInput(int lowerBound, int upperBound)
{
  int t = 0; //temporary validation storage
  do
  {
    cin >> t;
    cout << ((t < lowerBound || t > upperBound) ? "[Error] Try again:" : "");
  }while(t < lowerBound || t > upperBound);

  return t;
}

void getInput (Movie &movie)
{
  cout << endl;
  cout << "Movie Title: ";
  cin >>movie.title;

  cout << "Lead: ";
  cin >> movie.leadActor;

  cout << "On a scale of 1 to 10, rate the actor"
       << endl;

  cout << "Based on 'acting ability': some integer > ";
  movie.actorParam1 = validIntInput(1,10);

  cout << "Based on 'appearance' : some integer > ";
  movie.actorParam2 = validIntInput(1,10);

  cout << "Based on 'popularity' : some integer > ";
  movie.actorParam3 = validIntInput(1,10);

  cout << "On a scale of 1 to 10, rate the plot"
       << endl;

  cout << "Based on 'freshness': some integer > ";
  movie.plotParam1 = validIntInput(1,10);

  cout << "Based on 'execution': some integer > ";
  movie.plotParam2 = validIntInput(1,10);

  cout << "   ======================================   ";
  cout << endl << endl;

  return;
}

int calcRating(const int actorParam1,
               const int actorParam2,
              const int actorParam3)
{
  return(static_cast<int>((actorParam1 + actorParam2 + actorParam3)/3.0 + .5));
}

int calcRating(const int plotParam1, const int plotParam2)
{
  return(static_cast<int>((plotParam1 + plotParam2)/2.0 + .5));
}

void setOverallRating( Movie &movie)
{
  movie.overallRating = ((movie.actorRating + movie.plotRating)/2);
  return;
}

void printOutputs(const Movie &movie1, const Movie &movie2)
{
  printRatings("Actor", movie1.title, movie1.actorRating);
  printRatings("Actor", movie2.title, movie2.actorRating);
  cout << endl << endl;

  printRatings("Plot", movie1.title, movie1.plotRating);
  printRatings("Plot", movie2.title, movie2.plotRating);
  cout << endl << endl;

  printRatings("Overall rating", movie1.title, movie1.overallRating);
  printRatings("Overall rating", movie2.title, movie2.overallRating);
  cout << endl << endl;

  return;
}
