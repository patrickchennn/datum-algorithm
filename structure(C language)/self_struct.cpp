#include <iostream>
using std::cout;
using std::endl;

class Node{
public:
    int data1;
    char data2;
    Node* link;
};

int main(){
    Node object1; // node 1

    object1.link = NULL;
    object1.data1 = 10;
    object1.data2 = 'A';

    Node object2; // node 2
    object2.link = NULL;
    object2.data1 = 50;
    object2.data2 = 'B';

    // linking object1 and object2
    object1.link = &object2;

    printf("%d\n",object1.link->data1);
    printf("%c\n",object1.link->data2);

    /*
    lets proof that object1.link have the address of object2

    */
    printf("address of object2 %p\n",&object2);

    printf(
        "object1.link address pointing into %p\n",object1.link
    );
    return 0;
}


/*
DEF:
self referential structure is a structure whcih contains a pointer to a structure of the same type

https://www.geeksforgeeks.org/self-referential-structures/
*/