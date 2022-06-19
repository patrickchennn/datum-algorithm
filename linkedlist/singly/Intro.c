#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ // 0bytes
    int data; // 4bytes
    struct Node *next; // 8bytes
} Node;
/*
pictorially
---------------
| data | next |
---------------
*/

int main(){
    Node *head = NULL;
    printf("address head %p\n",head);
/*
pictorially
head=
---------------
|    NULL     |
---------------
*/

    head = (Node *)malloc(sizeof(struct Node));

    // after allocate heap memory
    printf("address head %p\n",head);


    head->data = 1;
    head->next = NULL;
    printf("%d\n",head->data);
    printf("head->%p\n",head->next);

    return 0;
}

/*
https://www.youtube.com/watch?v=DneLxrPmmsw&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=33
Creating the Node of a Single Linked List
*/