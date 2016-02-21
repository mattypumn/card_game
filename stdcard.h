#ifndef stdcard_h
#define stdcard_h


#include <iostream>
#include <string>
#include "card.h"

const string SUIT[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
const string VALUE[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };


class StdCard : public Card{
   int value; 
   int suit;    

  public: 
    StdCard();
    StdCard(int val, int suit); 

    void set_suit(int suit); 
    void set_value(int val); 
    
    bool has_suit(); 
    string get_value(); 
    string to_string(); 
    int get_value_int(); 
    int get_suit_int(); 

};



#endif
