#ifndef card_h
#define card_h

 
#include <iostream>
using namespace std;



class Card{
  public: 
    virtual bool has_suit() = 0; 
    virtual string get_value() = 0; 
    virtual string to_string() = 0;
    virtual int get_value_int() = 0;  
    virtual int get_suit_int() = 0; 

}; 



#endif
