/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/10/19
Description: This program works as a student database. The program prompts the
             user for an ID and marks for the amount of times in numOfStudents
             and enters in those values. Then, it calculates the minimum,
             maximum, and average values for all the marks in the array.
             Afterword, it prints the minimum, maximum, and average values.
*/

#include "lab9_header.h"

int main()
{
  //////////
  // Initialization of the array which will contain all students
  //////////
  Student students[10];

  //////////
  // Welcoming and formatting for input
  //////////
  cout << "Welcome to the Student Database!" << endl
       << "Please enter your values" << endl << endl;

  //////////
  // User input and array manipulation to store the values into students.
  //////////
  inputStudent(students);

  //////////
  // Output of the maximum, minimum, and average mark calculated through the
  // funcitons.
  //////////
  cout << "Maximum mark: " << maxMark(students) << endl
       << "Minimum mark: " << minMark(students) << endl
       << "Average mark: " << avgMark(students) << endl;

  return 0;
}
