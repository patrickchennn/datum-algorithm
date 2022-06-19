#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::vector;
using std::cin;

class Node{
public:
    int data;
    // int flag; //uncomment this to test approach 2
    Node *nextNode;
};

void PrintLL(Node *head);
void InsertNodeFromTail(Node **headReference, int data);

// hashmap approach
bool detectLoop(Node *head){
    std::unordered_set<Node*> seen; // we will store node address
    // and check if we encounter the same address
    // then list contains a loop
    while(head != NULL){
        if(seen.find(head) != seen.end()){
            return true;
        }
        seen.insert(head);
        head = head->nextNode;
    }
    return false;
}

// bool detectLoop2(Node *head){
//     while(head != NULL){
//         if(head->flag==1)
//             return true;
//         head->flag = 1;
//         head = head->nextNode;        
//     }
//     return false;
// }

bool detectLoop3(Node *head){
    Node *tortoise = head, *hare = head;

    // while(hare && tortoise && tortoise->nextNode){
    while(tortoise != NULL && tortoise->nextNode != NULL){
        hare = hare->nextNode;
        tortoise = tortoise->nextNode->nextNode;
        if(hare == tortoise)
            return true;
    }
    return false;
}

int main(){
    Node *head = NULL;
	InsertNodeFromTail(&head,2);
	InsertNodeFromTail(&head,3);
	InsertNodeFromTail(&head,4);
	InsertNodeFromTail(&head,5);

    // this statement will create a loop
    // 2 -> 3 -> 4 -> 2(back to head) -> 3 -> ...
	// head->nextNode->nextNode->nextNode = head;

// manual detect. the print statement goes infinite if and only if list contains loop
    cout << "head  = " << head << endl;
    Node *traverse = head;
    // while(traverse!=NULL){
    //     // printf("%p --> ",traverse); // node addresse
    //     printf("%d -> ",traverse->data); // node data
    //     traverse = traverse->nextNode;
    //     // test.insert(traverse);
    // }
    // puts("NULL");

// hashmap approach
    cout << std::boolalpha << detectLoop(head) << endl;

// 2nd
    // cout << std::boolalpha << detectLoop2(head) << endl;

// Floyd’s Cycle-Finding Algorithm 
    cout << std::boolalpha << detectLoop3(head) << endl;
    
	return 0;
}


/*
true=there is a loop
false=there is no loop

https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem?isFullScreen=false
https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
*/

void printLL(Node *head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
}

void InsertNodeFromTail(Node **headReference, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->nextNode = NULL;

    if((*headReference)==NULL){
        *headReference = newNode;
        return;
    }
    // we need to traverse the ll untill end-1 because we want to insert a new node at the end, and *traverseList will helps us to update the link
    Node *traverseList = *headReference;
    while(traverseList->nextNode != NULL){
        traverseList = traverseList->nextNode;
    }
    traverseList->nextNode= newNode;
    return;
}