#ifndef deck_h
#define deck_h


#include "card.h"
#include <vector> 


using namespace std; 

class Deck{
  private: 
    vector<Card*> cards; 
    // add int count;  

  public: 
     Deck(); 
     Deck(int type); 

     void add_card(Card* a); 
     Card* take_card(int index);

     int get_card_count(); 
     void see_top_card();
     void print_cards_in_deck();     
     
     void swap(int i, int j);  
     void shuffle();
     void sort(); 

};


#endif 
