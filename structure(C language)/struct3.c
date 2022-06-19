#include <stdio.h>

struct point
{
    int x,y;
};

struct point edit(struct point p)
{
    (p.x)++;
    p.y += 5;
    return p;
};

void print(struct point p){
    printf("(%d,%d)\n",p.x,p.y);
}

int main(){
    struct point p1={1,0};
    struct point p2={4,5};

    print(p1);
    print(p2);
    puts("-------------------");
    p1 = edit(p1);
    p2 = edit(p2);

    print(p1);
    print(p2);
    return 0;
}

/*
https://www.youtube.com/watch?v=bN2h1cdj1to&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=28
returning a structure variable from the function
*/