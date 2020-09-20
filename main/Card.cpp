// Card.cpp - Richard Forman
// Card class member function definitions

#include "stdafx.h"
#include <stdexcept>
#include "Card.h"
#include <string>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::strcpy;
using std::string;
using std::ostream;

// Card constructors
Card::Card()
: _firstname (""), _lastname (""), 
_occupation (""), _address (""), 
_phone ("") {}
Card::Card(string firstname, string lastname,
       string occupation, string address, 
       string phone )
: _firstname (firstname), _lastname (lastname), 
_occupation (occupation), _address (address), 
_phone (phone) {} //end constructor Card

// Card destructor
Card::~Card() {}

// member function show (display Card Contents)
void Card::show(ostream& os)   {
      os << "First Name: " << _firstname << endl
         << "Last Name: " << _lastname << endl
         << "Occupation: " << _occupation << endl
         << "Address: " << _address << endl
         << "Phone: " << _phone << endl << endl;
}

