// https://www.geeksforgeeks.org/linked-list-set-1-introduction/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ // 0 bytes
    int data; // 4bytes
    struct Node *next; // 8byes
} Node;

void countNodes(Node *head){
    // Linked List Traversal
    if(head == NULL){
        puts("List is empty!");
        return;
    }
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    puts("");

    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // expect results 0/null/nil
    printf("head address: %p\n",head);
    printf("second node address: %p\n",second);
    printf("third node address: %p\n\n",third);

    // check
    countNodes(head);

    // allocate 3 nodes at heap
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));

    // address
    printf("head address: %p\n",head);
    // printf("head address: %p\n",&head);
    printf("second node address: %p\n",second);
    printf("third node address: %p\n\n",third);

    // check 2
    printf("head->%d (data)\n",head->data);

    /* 
    proof that head does not pointing to any nodes
    */
    printf("head->%p\n",head->next);

    head->data = 5; // assign data in first node
    head->next = second; // Link first node with second

    // Now head is pointing to second node ADDRESS
    printf("head->%p\n",head->next);
    printf("%p->%p\n\n",head,head->next);


    second->data = 2;
    second->next = third;

    // second points to third ADDRESS
    printf("second->%p\n",second->next);
    printf("%p->%p\n\n",second,second->next);

    third->data = 3;
    third->next = NULL;

    // third points to NULL, meaning it's end of our list.
    printf("third->%p\n",third->next);
    printf("%p->%p\n\n",third,third->next);


    countNodes(head);
    return 0;
}
/*
what is "struct Node *next;" (?), well it's a:
self referential structure is a structure whcih contains a pointer to a structure of the same type
*/