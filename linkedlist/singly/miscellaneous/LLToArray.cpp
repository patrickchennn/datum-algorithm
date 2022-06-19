#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

/*
pictorially (Node is a cointainer basically)
------------------
| data | pointer |
------------------
*/
class Node{
public:
    int data;
    Node *nextNode;
};
void InsertNodeFromTail(Node **headReference, int data);

// print ll interative method
void printLL(Node *head);

void printVector(vector<int> &arr);
void toArr(Node *head,vector<int> &arr){
    while(head!=NULL){
        int data = head->data;
        arr.push_back(data);
        head = head->nextNode;
    }
}

int main(){
	Node *head = NULL;
    InsertNodeFromTail(&head,1);
    InsertNodeFromTail(&head,2);
    InsertNodeFromTail(&head,3);
    InsertNodeFromTail(&head,4);
    printLL(head);

    vector<int> arr;
    toArr(head,arr);
    printVector(arr);

	return 0;
}

/*

*/

void InsertNodeFromTail(Node **headReference, int data){
    Node *newNode = new Node();
    newNode->data = data;
    newNode->nextNode = NULL;

    if((*headReference)==NULL){
        *headReference = newNode;
        return;
    }
    // we need to traverse the ll untill end-1/before end, because we want to insert a new node at the end, and *traverseList will helps us to update the link
    Node *traverseList = *headReference;
    while(traverseList->nextNode != NULL){
        traverseList = traverseList->nextNode;
    }
    traverseList->nextNode= newNode;
    return;
}

void printLL(Node *head){
    while(head != NULL){
        printf("%d -> ",head->data);
        head = head->nextNode;
    }
    puts("NULL");
    // printf("expect 0/null %d\n",head);
}
void printVector(vector<int> &arr){
    for(auto &data : arr){
        cout << data << " ";
    }
    cout << '\n';
}