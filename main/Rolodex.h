// Richard Forman Rolodex.h
// Rolodex class declaration

#ifndef Rolodex_H
#define Rolodex_H


class Rolodex {
    public:
        Rolodex();    // ctor inits a new empty container
        ~Rolodex();   // dtor erases any remaining cards
        void add(Card& card);
        Card remove();
        Card getCurrent();
        Card flip();
        bool search(const std::string& Lastname, 
           const std::string& Firstname );
        void Show (std::ostream& os);
        void gotoStart();
        

        
    private:
        std::multimap< std::string, Card > mDex; // STL Container
        std::multimap< std::string, Card >::iterator mDexPos; // always points to the last QueueItem in the list
    
    };
 #endif