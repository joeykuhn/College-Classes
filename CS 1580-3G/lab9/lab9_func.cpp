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

void inputStudent(Student students[])
{
  for(int i=0;i<numOfStudents;i++)
  {
    cout << "ID of the student: ";
    cin >> students[i].ID;

    cout << "Marks for Student " << students[i].ID << ": ";
    cin >> students[i].marks;
    cout << endl;
  }


  return;
}

int maxMark(const Student students[])
{
  int maxMarks = students[0].marks;

  for(int i=1;i<numOfStudents;i++)
  {
    if(maxMarks < students[i].marks)
    {
      maxMarks = students[i].marks;
    }
  }

  return(maxMarks);
}

int minMark(const Student students[])
{
  int minMarks = students[0].marks;

  for(int i=1;i<numOfStudents;i++)
  {
    if(minMarks > students[i].marks)
    {
      minMarks = students[i].marks;
    }
  }

  return(minMarks);
}

float avgMark(const Student students[])
{
  float total = 0;

  for(int i=0;i<numOfStudents;i++)
  {
    total += students[i].marks;
  }

  return(total/numOfStudents);
}
