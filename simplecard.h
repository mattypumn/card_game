#ifndef simplecard_h
#define simplecard_h


#include <iostream>
#include <string>
#include "card.h"

using namespace std; 

const int MIN = 0; 
const int MAX = 59; 

class SimpleCard : public Card{
  int value;

  public: 
    SimpleCard(); 
    SimpleCard(int val); 
    string get_value(); 
    string to_string();  
    bool has_suit();
    void set_value(int n);  
    int get_value_int();


//    bool less_than(SimpleCard* y);
     
//    bool operator<(SimpleCard y);
//    bool operator<(SimpleCard* y);  
//    bool operator>(SimpleCard y);
//    bool operator>(SimpleCard* y); 
}; 

#endif
