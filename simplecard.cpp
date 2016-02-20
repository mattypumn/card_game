
#include <iostream>
#include <string>
#include "simplecard.h"



SimpleCard::SimpleCard(){        /************* testing */ 
}

SimpleCard::SimpleCard(int val){
  if(val < MIN){ 
    cout << "Val was less than MIN !!" <<  endl; 
  } else if (val > MAX ){
    cout << "Val was greater than MAX !!" << endl; 
  } else{
   value = val; 
  }
}


void SimpleCard::set_value(int n){
  value = n; 
}

bool SimpleCard::has_suit(){
  return 0; 
}

string SimpleCard::get_value(){
  string str = std::to_string(value); 
  return str; 
}

string SimpleCard::to_string(){
  string str = std::to_string(value); 
  return str; 
}


int SimpleCard::get_value_int(){
  return value;
}

//bool SimpleCard::less_than(){
//  return 0; 
//}


/*  Siimple card comparison
 *  x.less_than(y)  
 *  return True iff x->value  < y->value  
 */ 

/*
bool SimpleCard::less_than(SimpleCard* y){
  return value < y->get_value_int();
}

bool SimpleCard::operator<(SimpleCard other){
  return value < other.get_value_int(); 
}

bool SimpleCard::operator<(SimpleCard* y){
  return value < y->get_value_int(); 
}  
bool SimpleCard::operator>(SimpleCard y){
  return value > y.get_value_int(); 
}
 bool SimpleCard::operator>(SimpleCard* y){
  return value > y->get_value_int(); 
}
*/
