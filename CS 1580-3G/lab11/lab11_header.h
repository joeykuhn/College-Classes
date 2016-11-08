/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/11/02
Description: This function takes input relationship, name, and amount of family
             members from a file and outputs their thanksgiving invitations
             to another file.
*/
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

struct family
{
  int numOfFam;
  string name;
  string relationship;
};

ostream& operator << (ostream &out, const family &fam);

#endif
