#include <stdio.h>
#include <stdlib.h>

int main(){
    /* This pointer will hold the
    base adress of the block created
    */
    int size;
    int *ptr;

    printf("Enter number of values you want to store(size of array):");
    scanf("%d", &size);
    
    ptr = malloc(sizeof(size));

    printf("Enter values to be stored in the array\n");
    for(int i = 0; i < size; i++){
        scanf("%d", &ptr[i]);
    }
    printf("Values in the array are: \n");
    for(int i = 0; i < size; i++){
        printf("%d\n", ptr[i]);
    }
    return 0;
}
