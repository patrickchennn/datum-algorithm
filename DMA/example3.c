#include <stdio.h>
#include <stdlib.h>

int main(){
    char inputValue;
    char *ptr;

    printf("Enter your name:");
    scanf("%s", &inputValue);
    ptr = (char*)malloc(inputValue * sizeof(char));

    printf("Hello %s!\n", ptr);
    exit(0);
}