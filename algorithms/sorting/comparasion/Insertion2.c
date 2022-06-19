#include <stdio.h>
#include <stdbool.h>

#define MAX 7

void printline(int count);
void display();

void insertionSort(int intArray[]) {

   int valueToInsert;
   int holePosition;
   int i;
  
   // loop through all numbers 
   for(i = 1; i < MAX; i++) { 
	
      // select a value to be inserted.
      valueToInsert = intArray[i];
		
      // select the hole position where number is to be inserted 
      holePosition = i;
		
      // check if previous no. is larger than value to be inserted 
      while (holePosition > 0 && intArray[holePosition-1] > valueToInsert) {
         intArray[holePosition] = intArray[holePosition-1];
         holePosition--;
         printf(" item moved : %d\n" , intArray[holePosition]);
      }

      if(holePosition != i) {
         printf(" item inserted : %d, at position : %d\n" , valueToInsert,holePosition);
         // insert the number at hole position 
         intArray[holePosition] = valueToInsert;
      }

      printf("Iteration %d#:",i);
      display(intArray);
		
   }  
}

void main() {
    int intArray[MAX] = {4,6,3,2,1,9,7};
    printf("Input Array: ");
    display(intArray);
    printline(50);
    
    insertionSort(intArray);
    printf("Output Array: ");
    display(intArray);
    printline(50);
}

void printline(int count){
    for(int i = 0;i < count-1;i++)
        printf("=");
	
    printf("=\n");
}

void display(int intArray[]) {
   int i;
   printf("[");
	
   // navigate through all items 
   for(i = 0;i < MAX;i++) {
      printf("%d ",intArray[i]);
   }
	
   printf("]\n");
}