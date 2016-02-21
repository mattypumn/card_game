


#include <iostream>
#include "card.h"
#include "simplecard.h"
#include "stdcard.h"
#include <vector> 
#include "decksort.h"
#include "deck.h"



/********************* constructor  *************************/


Deck::Deck(){
  
}

Deck::Deck(int type){  // type should be either one or two ! 
  int i, j;
 
  if(type == 1){		
    
    // this creates the simple deck 
    for(i=0; i < 60; i++){ 
      cards.push_back(new SimpleCard(i));
    } 
  

  }else if(type ==2 ){	
    // this creates a std deck
    // for loop to make all the possible cards.
    
    for(i = 0; i < 4; i++){ 
      for(j = 0; j < 13; j++){
          cards.push_back(  new StdCard(j,i)  );  
      } // end j-loop 
    } // end i-loop 
  }else{     			// error
    cerr << "Problem with type in Deck(int type)" << endl; 
    exit(0); 
  } // end if(type ...
}


/******  setters *******/ 

void Deck::add_card(Card* a){
    cards.push_back(a); 
}


/* Swap the two indexes passed int
 *
 */ 
void Deck::swap(int i, int j){
  Card* temp = cards[i]; 
  cards[i] = cards[j]; 
  cards[j] = temp; 
}

/* shuffle the cards remaining in deck
 * 
 */ 

void Deck::shuffle(){
  int deck_count = cards.size(); 
  int i, j; 
  for(i = 1; i < deck_count; i++){
    j = rand()  % (i);
    Deck::swap(i,j); 
  }  
}

/* Sort the cards remaining in deck
 * 
 */ 
void Deck::sort(){
  if(cards.size() == 0 ){
    return; 
  }
  cout << "Sorting... " << endl;   
  merge_sort(cards, 0); 
  

  if(  cards[0]->has_suit() ){  
     cout << "Deck Has suits !" << endl; 
     merge_sort(cards, 1);  
  } 

}





/******     Getters *******/ 

/* take_random_card() 
  remove card for deck and return it
  useful to take a card from deck and put in hand 
*/   
Card* Deck::take_card(int index){
  Card* r_card = cards[index];
  cards.erase( cards.begin()+index );

  return r_card;   
}



/*  Print the Top card in the deck! 
*/ 
void Deck::see_top_card(){
 // Card* s_card = cards.back(); 
  cout << cards.back()->to_string();   
}


/*  return the number of cards still in deck
 * 
 */ 
int Deck::get_card_count(){
  return cards.size(); 
}

/*  send values of cards 
 *  bottom to top separated by \n
 */ 
void Deck::print_cards_in_deck(){
  
  if(cards.size() == 0){
    cout << "DECK HAS NO CARDS TO PRINT" <<  endl; 
    return; 
  } 
  int i; 
  for(i = 0; i < cards.size(); i++){
    string element_string = cards[i]->to_string(); 

    cout << i+1 << ": " << element_string << endl; 
  }
  cout << endl;  
}





