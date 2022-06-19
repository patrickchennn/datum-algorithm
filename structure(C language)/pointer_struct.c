#include <stdio.h>

struct point{
    int x;
    int y;
};

void printStruct(struct point *ptr){
    printf("%d %d\n", ptr->x, ptr->y);
}

int main(){
    struct point p1 = {1,2};
    struct point p2 = {3,4};

    // pass by reference
    printStruct(&p1);
    printStruct(&p2);
    return 0;
}

/*
in file we demonstrate how to:
passing pointers to structures as arguments
https://www.youtube.com/watch?v=f-AR6vUuTYc&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=27
*/