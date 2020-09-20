// Card.h - Richard Forman
// Card class declaration. 
// Member functions are defined in Card.cpp

// prevent multiple inclusions of header
#ifndef CARD_H
#define CARD_H


// class Card declaration
class Card {
public:
    Card();
    Card(std::string firstname, std::string lastname,
       std::string occupation, std::string address, 
       std::string phone ); // ctor
    ~Card();                // dtor
    std::string getfname() { return _firstname; };
    std::string getlname() { return _lastname; };
    std::string getocc() { return _occupation; };
    std::string getaddr() { return _address; };
    std::string getphone() { return _phone; };
    void setfname( std::string firstname ) { _firstname = firstname; };
    void setlname( std::string lastname ) { _lastname = lastname; };
    void setocc( std::string occupation ) { _occupation = occupation; };
    void setaddr( std::string address ) { _address = address; };
    void setphone (std::string phone ) { _phone = phone;  };
    void show(std::ostream& os);

    
private:
   std::string _firstname;
   std::string _lastname;
   std::string _occupation;
   std::string _address;
   std::string _phone;

};
#endif