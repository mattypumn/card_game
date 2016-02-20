
#include <iostream>
#include <string>
#include "stdcard.h"
/*****************************************************************
Assuming inputs are good  ----- fix later
*****************************************************************/

StdCard::StdCard(){
  value = '\0';
  suit = '\0'; 
}

StdCard::StdCard(int val, int suit){
  this->suit = suit;
  this->value = val;
}

void StdCard::set_suit(int suit){
  this->suit = suit;  
}


void StdCard::set_suit(char suit){
/*  this->suit = suit;   */
}


void StdCard::set_value(int val){
  value = val; 
} 

void StdCard::set_value(string val){
/*  this->value = val; */
}

/* Get the string which correlates
 * to the VALUE[value] 
 */ 
string StdCard::get_value(){
  return VALUE[value]; 
}

int StdCard::get_value_int(){
  return value; 
}

string StdCard::to_string(){
  return VALUE[value]  + " of " + SUIT[suit] ; 
}

bool StdCard::has_suit(){
  return 1; 
}
int StdCard::get_suit_int(){
  return suit; 
}


bool StdCard::less_than(StdCard* y){
  
  return 0; 

} 



/*
bool StdCard::operator<(StdCard y){
  return  value < y.get_value_int(); 
}

bool StdCard::operator<(StdCard* yp){
  return value < yp->get_value_int(); 
}

bool StdCard::operator>(StdCard y){
  return value > y.get_value_int(); 
}

bool StdCard::operator>(StdCard* yp){
  return value > yp->get_value_int();
}



bool StdCard::suit_less_than(StdCard y){
  return suit < y.get_suit_int();  
}

bool StdCard::suit_less_than(StdCard* yp){
  return suit < yp->get_suit_int(); 
}
*/

