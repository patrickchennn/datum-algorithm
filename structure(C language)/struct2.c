#include <stdio.h>

struct point{
    int x;
    int y;
};

void printStruct(struct point ptr){
    printf("%d %d\n", ptr.x, ptr.x);
}

int main(){
    struct point p1 = {1,2};
    struct point p2 = {3,4};

    // pass by value
    printStruct(p1);
    printStruct(p2);
    return 0;
}

/*
in file we demonstrate how 
passing structure variable as argument

https://www.youtube.com/watch?v=uw8gkmhUwQ8&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=25
*/