// main.cpp : Defines the entry point for the console application.
//
#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Card.h"
#include "Rolodex.h"

using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::endl;
using std::ifstream;
using std::ios;
using std::left;
using std::setw;
using std::getline;
using std::multimap;
using std::less;
using std::make_pair;
using std::pair;
using std::ostream;

int main()
{
   // If stream constructor
   ifstream inClientFile( "RolodexData_sem_only.txt", ios::in );
   if ( !inClientFile )
   {
      cerr << "File could not be opened" << endl;
      exit ( EXIT_FAILURE );
   } // end if

   string firstname;
   string lastname;
   string occupation;
   string address;
   string phone;
   
   multimap< string, Card > pairs; // create multimap
   multimap< string, Card >::iterator itr;

   cout << " welcome to Rolodex\n\n "
      << " Reading in cards from file\n\n";

   
   Rolodex myrolo;
   // read in cards from file
   while ( inClientFile )
      {
         getline(inClientFile, firstname, ';' );
         getline(inClientFile, lastname, ';' );
         getline(inClientFile, occupation,';' ); 
         getline(inClientFile, address, ';' );
         getline(inClientFile, phone);
         if (inClientFile.tellg() <  0) //exits the loop at EOF
            break;
         //outputline ( firstname, lastname, 
         //   occupation, address, phone );
         Card roloCard = Card(firstname, lastname,
            occupation, address, phone);

         myrolo.add( roloCard );
         
            
      }

   myrolo.gotoStart();

  
   string request = "";
   while ( request != "quit" ){
      // prompt for input
      cout << "please enter one of the commands:\n"
         << "list, view, flip, add, remove, search, quit\n\n"
         << "command:";

      getline( cin, request);

      if (request == "list" )   //list all cards
         myrolo.Show( cout );
      
      else if
         ( request == "quit" )  // exit program
         cout << "Ciao!\n";

      else if
         (request == "view" ){  // display current card
         Card current= myrolo.getCurrent();
         current.show( cout );
      }

      else if
         ( request == "flip" ){ // flip to next card
         Card current = myrolo.flip();
         current.show( cout );
      }

      else if
         ( request == "add" ){ // add card to multimap
            Card newcard; // invoke default constructor
            string fname, lname, occ, addr, phn; // declare vars
            cout << "please enter first name:";  
            getline( cin, fname); 
            newcard.setfname(fname);
            cout << "please enter last name:";
            getline( cin, lname);
            newcard.setlname(lname);
            cout << "please enter occupation:";
            getline( cin, occ );
            newcard.setocc(occ);
            cout << "please enter address:";
            getline( cin, addr );
            newcard.setaddr(addr);
            cout << "please enter phone:";
            getline (cin, phn) ;
            newcard.setphone(phn);

            myrolo.add(newcard);
            bool Dummy = myrolo.search(lname,fname);
      }

      else if
         (request == "remove"){
            string response;
            cout << "\n Current card is :\n";
            Card removedCard = myrolo.getCurrent();
            removedCard.show(cout);
            cout << "\nDo you really want to delete this?:" << endl;
            cout << "enter Y (for Yes) or N (for No):";
            getline( cin, response);
            if ( "Y" == response ){
               removedCard.show(cout);
               removedCard = myrolo.remove();
               cout << "deleted\n\n";
               
            }
            else if ( "N" == response )
               cout << "saved\n";
            else
               cout << "invalid input. Card untouched.\n"
               << "Retry if you still want to remove the card\n\n";
      }

      else if ( "search" == request ){
         string fname,lname;
         cout << "please enter first name:";  
         getline( cin, fname); 
         cout << "please enter last name:";
         getline( cin, lname);
         bool found = myrolo.search(lname,fname);
         if (found == true){
            cout << "\nfound:\n";
            Card foundCard = myrolo.getCurrent();
            foundCard.show(cout);
         }
         else
            cout << "\nNot found\n";
         
      }

      else
         cout << "try again";
   }

	
}

