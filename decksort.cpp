#include <iostream>
#include <cstdlib>
#include <vector>

#include "decksort.h"
#include "card.h"

void merge(vector<Card*>& cards, vector<Card*>& v2, int left, int mid, int right){
/****************************************************************
  cout << "merging: " << endl
       << "\tleft: " << left << endl
       << "\tmiddle: " << mid << endl 
       << "\tright: " << right << endl; 
**************************************************************/
   
   /** Copy into first array to put back nicely in 2nd  */
  for(int k = left; k <= right; k++){


    v2[k] = cards[k];


/**********************************************************
  cout << "v2[" << k << "]:  " << v2[k]->get_value() << endl;  
**********************************************************/ 
 }    
  


 
  int i = left, 
      j = mid+1;
 


  for(int k = left; k <= right; k++){

    if(i > mid){  


/******************************************************************
      cout << "i > mid" << endl; 
	cout << "j:  " << j << "\ti:  " << i << endl; 	
      cout << "v2[j]:  " << v2[j]->get_value() << endl; 
******************************************************************/


      cards[k] = v2[j]; 

      j++; 

/******************************************************************
      cout << "cards[k]:  " << cards[k]->get_value() << endl;  
******************************************************************/


    }else if(j > right){



/******************************************************************
      cout << "j > right " << endl;
      cout << "j:  " << j << "\ti:  " << i << endl; 
******************************************************************/


      cards[k] = v2[i]; 
      i++; 
   


/******************************************************************
      cout << "cards[k]:  " << cards[k]->get_value() << endl;  
******************************************************************/


    }else if( v2[j]->get_value_int() < v2[i]->get_value_int()  ){       // <---------------------------------------------

/******************************************************************
	cout << "j:  " << j << "\ti:  " << i << endl; 	
       cout << "v2[j] < v2[i]" << endl   ;    
       cout << "v2[j]:  " << v2[j]->get_value() << endl; 
     	cout << "v2[i]:  " << v2[i]->get_value() << endl; 
******************************************************************/


      cards[k] = v2[j];



/******************************************************************
      cout << "cards[k]:  " << cards[k]->get_value() << endl;  
******************************************************************/


      j++; 


    }else{
/******************************************************************
     cout << "in 'else' case in merge: " << endl; 
	cout << "j:  " << j << "\ti:  " << i << endl; 	
       cout << "v2[j]:  " << v2[j]->get_value() << endl; 
     	cout << "v2[i]:  " << v2[i]->get_value() << endl; 
******************************************************************/

      cards[k] = v2[i]; 
      i++; 


/******************************************************************
      cout << "cards[k]:  " << cards[k]->get_value() << endl;  
******************************************************************/

    }  

/*********************************************************************
 // cout << cards[k]->to_string() << endl; 

*********************************************************************/




  }// end k-loop
 
}// end merge 


void merge_sort(vector<Card*>& cards, vector<Card*>& v2, int start, int end){
   if(end  <= start){
     return; 
  } 
  


  int middle = start + (end - start) / 2; 


  /*********TESTING ********************************
  cout << "start: " << start <<
          "   middle: " << middle << 
          "    end: " << end  << endl; 
  **************************************************/

  merge_sort(cards, v2, start, middle); 
  merge_sort(cards, v2, middle+1, end); 
 
  merge(cards, v2, start, middle, end); 
}


void merge_sort(std::vector<Card*>& cards){ 
   cout << "Sorting ... " << endl; 
  if(cards.size() == 0)  return; 
 
/****************************************************
  cout << "Bottom card:  " << cards[0]->to_string() << endl;  

********************************************************/
 



  vector<Card*> v2(cards);






/************************************************************

  cout << "bottom of second deck:  " << v2[0]->to_string() << endl;
//return;  
*******************************************************************/
 
  int start = 0;
  int end = cards.size()-1;  
  int middle = start + (end - start) / 2; 

/***************************************************************************8*****/

/*********************************************************************************/

  merge_sort(cards, v2, start, end); 
}

void merge_sort(){
  cout << "Doing nothing ..." << endl;
}








