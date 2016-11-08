/*
Programmer: Kevin Schoonover
Instructor: Maria Angelin John Bosco
Section: G
Date: 2016/11/02
Description: This function takes input relationship, name, and amount of family
             members from a file and outputs their thanksgiving invitations
             to another file.
*/
#include "lab11_header.h"

//////////
// @Pre: fam must hve relationship and name defined or convertable to strings.
// @Post: The dinner invitation will be outputted to the output stream
// @Desc: This function takes in a family and outputs their thanksgiving dinner
//        invitation to the output stream.
//////////
ostream& operator << (ostream &out, const family &fam)
{
  out << "--------------------------------------------------------" << endl
      << endl
      << "THANKSGIVING DINNER INVITATION" << endl << endl
      << "Dearest " << fam.relationship << " " << fam.name
      << ", we cordially invite you and your family to the "
      << "Thanksgiving Dinner on November 22nd, hosted by the Schoonover's."
      << " We hope to see you soon."
      << endl << endl;

  return(out);
}
