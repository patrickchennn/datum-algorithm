#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x,y;
};

struct point *edit(int a,int b)
{
    struct point *ptr = 
    (struct point *)malloc(sizeof(struct point));

    ptr->x = a;
    ptr->y = b;
    return ptr;
    
};

void print(struct point* p){
    printf("(%d,%d)\n",p->x,p->y);
}

int main(){
    struct point *ptr1,*ptr2;
    ptr1 = edit(1,5);
    ptr2 = edit(4,10);


    // printf("(%d,%d)\n",ptr1->x,ptr1->y);

    //access value using function
    print(ptr1);
    print(ptr2);
    printf("sizeof %ld\n",sizeof(ptr1));

    // deallocating memory
    free(ptr1);
    free(ptr2);

    ptr1=NULL;
    printf("sizeof %ld\n",sizeof(ptr1));

    return 0;
}


/*
https://www.youtube.com/watch?v=NA_bM5Jwxiw&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=28
returning a pointer to a structure from the function
*/