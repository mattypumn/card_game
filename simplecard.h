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
    
    void set_value(int n);  
    
    string get_value(); 
    string to_string();  
    bool has_suit();
    int get_value_int();
    int get_suit_int(); // needed since I stuck with pure abstract class
                        // I need to use template !!!!  
}; 

#endif


