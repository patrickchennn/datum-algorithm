#include <stdio.h>
#include <stdlib.h>

int main(){
    /* 
    This pointer will hold the
    base addres of the block created
    */
    int* ptr;
    int ourInput;

    // get the number of elements for the array
    
    printf("Enter number of elements: ");
    scanf("%d", &ourInput);

    // Dynamically allocate mem using malloc()
    ptr = (int*)malloc(ourInput * sizeof(int));

    //check if the mem has been successfully
    // allocated by malloc or not

    if(ptr == NULL){
        printf("Memory not allocated.\n");
        exit(1);
    }else{
        // mem has been successfully allocated
        printf("Memory successfully allocated using malloc.\n");

        // get the elements of the array
        for(int i = 0; i < ourInput; i++){
            ptr[i] = i + 1;
        }
        // print the elements of the arry
        printf("Print the elements of the array are: ");
        for(int i = 0; i < ourInput; i++){
            printf("%d ", ptr[i]);
        }
        printf("\n");
    }
    return 0;
}