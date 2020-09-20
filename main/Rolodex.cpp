// Richard Forman Rolodex.cpp
// Rolodex member function definitions

#include <sstream>
#include <iostream>
#include <map>
#include <iterator>
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
using std::distance;
using std::next;


//constructor
Rolodex::Rolodex(){
   multimap< string, Card > mDex;
   multimap< string, Card >::iterator mDexPos;
}
// Dtor
Rolodex::~Rolodex(){
   mDex.clear();
}
void Rolodex::add(Card& card){
   mDex.insert(pair< string, Card >
      ( card.getlname() + card.getfname(), card ));
}

Card Rolodex::remove(){
   Card cardRemoved = mDexPos->second;
   string key = mDexPos->first;
   Card nextCard = flip();
   mDex.erase( key );
   mDexPos = mDex.find(nextCard.getlname()+nextCard.getfname());
   return cardRemoved;
}

Card Rolodex::getCurrent(){
   return mDexPos->second;
}
Card Rolodex::flip(){
   if ( distance(mDexPos , mDex.end()) >1 ){
      ++mDexPos;
      return getCurrent();
   }
   else{
      mDexPos = mDex.begin();
      return getCurrent();
   }
}
bool Rolodex::search(const string& Lastname, const string& Firstname ){
   multimap< string, Card >::iterator SavedDexPos = mDexPos;
   bool found = false;

   mDexPos = mDex.find(Lastname + Firstname); // use multimap find member function
   if ( mDexPos != mDex.end())
      return true;
   
   else
      mDexPos = SavedDexPos;
      for ( multimap< string, Card >::iterator 
         LoopDexPos = mDex.begin() ; LoopDexPos != mDex.end() ; 
         ++ LoopDexPos ){
            Card loopcard = LoopDexPos->second;
            if ( (loopcard.getlname() + loopcard.getfname()) > 
               (Lastname + Firstname) ){
               if ( distance(LoopDexPos,mDex.end() ) >1 ){
                  mDexPos = LoopDexPos;
                  getCurrent();
                  found = true;
                  break;
               }
               else{
                  mDexPos = SavedDexPos;
                  found = false;
               }
               break;
            }
      return found;
      }
         
}
void Rolodex::Show(ostream& os){
   for ( multimap< string, Card >::iterator 
         showDexPos = mDex.begin() ; showDexPos != mDex.end() ;
         showDexPos++ ){
            //string key = showDexPos->first;
            //cout << "key =:" << key << endl; // output value of key
            showDexPos->second.show(os);
   }
}
void Rolodex::gotoStart(){
   mDexPos = mDex.begin();
}



