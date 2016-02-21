
#include <iostream>
#include <string>
#include "stdcard.h"


/********** Constructors **********/ 


/* null constructor
 */ 
StdCard::StdCard(){
  value = '\0';
  suit = '\0'; 
}

/*  constructor with both val given
 */ 
StdCard::StdCard(int val, int suit){
  this->suit = suit;
  this->value = val;
}


/* void set_suit(int suit)
 *  used to change the suit
 */ 
void StdCard::set_suit(int suit){
  this->suit = suit;  
}


/*  void set_value(int val)
 *  used to change the value of card
 */ 
void StdCard::set_value(int val){
  value = val; 
} 



/* Get the string which correlates
 * to the VALUE[value] 
 */ 
string StdCard::get_value(){
  return VALUE[value]; 
}


/* get the value of card in int form 
 * return int
 */ 
int StdCard::get_value_int(){
  return value; 
}

/* card with value = 0; and suit = 0
 *   -->   2 of Clubs 
 * return string 
 */ 
std::string StdCard::to_string(){
  return VALUE[value]  + " of " + SUIT[suit] ; 
}

/* needed to make this work without template
 * 
 */
bool StdCard::has_suit(){
  return 1; 
}

/* get the suit int form 
 * return int 
 */ 
int StdCard::get_suit_int(){
  return suit; 
}




