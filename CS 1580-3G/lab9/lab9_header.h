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

#ifndef HEADER_H
#define HEADER_H

#include <iostream>

using namespace std;

const int numOfStudents = 7;

struct Student{
  int ID;
  int marks;
};



//////////
// @Pre: The values student[0...numOfStudents-1] must be defined within the
//       array.
// @Post: Inputs the user entered values for ID and marks into their respective
//        index up to numOfStudents-1
// @Description: This function asks the user for an input for ID and mark up to
//               numOfStudents times and enters those valuse into the students
//               array with their respective indexes
//////////
void inputStudent(Student students[]);

//////////
// @Pre: The values student[0...numOfStudents-1] must be defined within the
//       array.
// @Post: Returns the maximum mark from all of the arrays
// @Description: This function iterates through all of the items within the
//               array and checks to see which has the maximum mark. After
//               the iteration, it returns the value.
//////////
int maxMark(const Student students[]);

//////////
// @Pre: The values student[0...numOfStudents-1] must be defined within the
//       array.
// @Post: Returns the minimum mark from all of the arrays
// @Description: This function iterates through all of the items within the
//               array and checks to see which has the minimum mark. After
//               the iteration, it returns the value.
//////////
int minMark(const Student students[]);

//////////
// @Pre: The values student[0...numOfStudents-1] must be defined within the
//       array and student[n].mark > 0.
// @Post: Returns the average of all of the marks in the array
// @Description: This function iterates through the array, adding all of the
//               values to a total, then divides that total by numOfStudents.
//               After which, it returns that value.
//////////
float avgMark(const Student students[]);

#endif
