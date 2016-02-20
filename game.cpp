#include <iostream>
#include "deck.h"
#include <ctime>
#include <cstdlib>


using namespace std;

int choose_deck(); 
void play_game(Deck deck);  // this is going to get messy... perhaps put in different file

int main(){
  
  // get choice of deck from user 
  int deck_type = choose_deck();   


  // build deck 
  Deck _deck (deck_type);
  
  // play game
   play_game(_deck); 

  
// exit nicely 
  return 0; 
}

/*  Function which promps user to choose the deck type
    Only accepts '1' or '2' as input.
    will run forever until it gets proper input   
*/
int choose_deck(){
  string input = ""; 
  int choice; 
  
  // prompt user
  cout << "\nHello! Choose which deck to use:" << endl; 
  cout << "  1. Simple Deck" << endl; 
  cout << "  2. Traditional Deck" << endl; 

  // get input 
  getline(cin, input); 
  
  // make sure input is valid
  while(  (input != "1")   &&  (input != "2")  ){
    cout << "Sorry, you entered: " << input << endl; 
    cout << "Please pick 1 or 2!" << endl; 
    getline(cin, input); 
  }   
 
  // converting input to int 
  choice = atoi(input.c_str()); 

  // return input as int
  return choice; 
}



void play_game(Deck deck){
/*******************************************  fix later *****      */ 
  Deck hand;    // very similar to deck.. lets just use the class for now 
  string input = ""; 
  int command = -1; 
 
  // initialize random seed for sorting 
  srand(time(NULL));   

  while ( input != "6"){
     cout << "Choose an option:" << endl; 
     cout << "  1. Draw a card to hand" << endl; 
     cout << "  2. Place a card in hand on the deck" << endl; 
     cout << "  3. Shuffle the deck" << endl; 
     cout << "  4. Sort the deck" << endl; 
     cout << "  5. Print cards that exist in hand" << endl; 
     cout << "  6. Quit" << endl; 

     getline(cin, input); 
     command = atoi(input.c_str()); 

     //  execute users command
     switch(command){
        
        /****  case 1   pull random card from deck *****/
	case 1: 
   	{
   	    int index;

	    //make sure deck is not empty 
            if(  deck.get_card_count() == 0 )
 		break;   
	    
            // use random to get the ecxhange 
  	    index = rand() % deck.get_card_count();
	    
	    // make the exchange
	    hand.add_card( deck.take_card(index)  ); 
	    
 	    // friendly message 
	    cout << "You drew: "; 
	    hand.see_top_card();
	    cout << endl;  
	    break;  
 	}


	/***** Case 2:  Put a card from hand to deck   **/ 
	case 2:
	{
	  int hand_count = hand.get_card_count(); 
	  int index; 
	  string input = ""; 

	  // if empty hand do nothing.
 	  if (!hand_count){  
            	cout << ".. but you have nothing in your hand .. " << endl;
 		break;   
          } 
	  
          cout << "Pick which card to put back!" << endl;
	  cout << "Your Hand:" << endl;
 	  hand.print_cards_in_deck();

 	  getline(cin, input); 
	  index = atoi(input.c_str()) - 1; 

		// make sure input is valid
	  while(index <0 || index > (hand_count - 1)){
		cout << "Please pick a number corresponding to a card" << endl; 
	        hand.print_cards_in_deck();
		getline(cin, input); 
		index = atoi(input.c_str() - 1);  
	  }
	  
          // move card from hand to deck. 
	  deck.add_card( hand.take_card(index));
	  
   	  // friendly message for user 
	  cout << "You put "; 
	  deck.see_top_card(); 
	  cout << " on the top of the deck" << endl; 
	  break;
	}

        /*  Case 3:   Shuffle Deck   */ 	 
	case 3:
          cout << "Shuffling..." << endl;
	  deck.shuffle(); 
 	  break; 
       


	/****Case 4:  Sort Deck ***/ 
	case 4: 
          deck.sort();
	  break; 
	
	
	/****  Case 5:  Pring users hand ***/ 
	case 5: 
          cout << "Your hand:" << endl; 
          //hand.sort();
	  hand.print_cards_in_deck(); 
	  break; 

         
        /****     exta to test shuffle and sort *****/ 
	case 7:  // print deck

	   deck.print_cards_in_deck(); 
	   break; 
             

       default: 
         // do nothing
 	  break; 

    } // end of switch(command)

  }// end of while(input != "6") 

}// end of play_game()

 
