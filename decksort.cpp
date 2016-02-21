#include <iostream>
#include <cstdlib>
#include <vector>

#include "decksort.h"
#include "card.h"

void merge(vector<Card*>& cards, vector<Card*>& v2, int left, int mid, int right, int comparator){
  // iterators 
  int i = left, 
      j = mid+1,
      k; 


   /** Copy into first array to put back nicely in 2nd  */
  for(int k = left; k <= right; k++) { 
    v2[k] = cards[k];
  }    


  for(int k = left; k <= right; k++){
    // i is finished with left half
    if(i > mid){  
      cards[k] = v2[j]; 
      j++; 

    // if j is finished with right half
    }else if(j > right){
      cards[k] = v2[i]; 
      i++; 

/*  this is a contrived implementation using only abstract classes
 *  to work a proper compareTo method, my classes would need to be templates
 *  stay tuned.......
 */ 
    // actually check v2[j] < v2[i]  
    }else if(comparator && (v2[j]->get_suit_int() < v2[i]->get_suit_int()) ){
       cards[k] = v2[j]; 
       j++; 
    }else if(!comparator && (v2[j]->get_value_int() < v2[i]->get_value_int() )){

       cards[k] = v2[j]; 
       j++;  

    // v2[i] >= v2[j] 
    }else{

      cards[k] = v2[i]; 
      i++; 
    }  

  }// end k-loop
 
}// end merge 


void merge_sort(vector<Card*>& cards, vector<Card*>& v2, int start, int end, int comparator){
   if(end  <= start){
     return; 
  } 

  int middle = start + (end - start) / 2; 

  // recursive calls
  merge_sort(cards, v2, start, middle, comparator); 
  merge_sort(cards, v2, middle+1, end, comparator); 
 
  merge(cards, v2, start, middle, end, comparator); 
}

//  help prepare for the actual merge_sort recursive calls
void merge_sort(std::vector<Card*>& cards, int comparator){ 
  if(cards.size() == 0)  return; 

  vector<Card*> v2(cards);
 
  int start = 0;
  int end = cards.size()-1;  
  int middle = start + (end - start) / 2; 

  // 3, 2, 1  GO !!!!
  merge_sort(cards, v2, start, end, comparator); 
}









