#include <stdlib.h>
#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};

int countNodes(struct Node *p){
    int count = 0;
    while(p != NULL){
        // printf("%d\n", p->data);
        p = p->next;
        count += 1;
    }
    return count;
}

void printList(struct Node *n){
    while(n != NULL){
        printf("%d ",n->data);
        n = n->next;
    }
    printf("\n");
}

int main(){
    // Initialize nodes
    struct Node *head;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;
    struct Node *fifth = NULL;
    struct Node *sixth = NULL;

    // Allocate memory dynamically
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));
    sixth = (struct Node*)malloc(sizeof(struct Node));

    // assign value
    second->data = 2;
    third->data = 3;
    fourth->data = 5;
    fifth->data = 2;
    sixth->data = 10;

    // connect nodes
    head = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;
    
    // printing node-value
    printf("%d\n",countNodes(head));
    printList(head);
    return 0;
}