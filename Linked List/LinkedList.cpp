//insersion in linked list;

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Node
{
    int value;
    struct Node* next;
};

struct List
{
    int size;
    struct Node* next;
};
typedef struct Node* nodeptr;
typedef struct List* list;

nodeptr createNode(int value){
    // nodeptr head = (nodeptr) malloc(sizeof(nodeptr)); for c
    nodeptr head = new (struct Node); // for c++;
    head->next = NULL;
    head->value = value;
    return head;
}

list createList(){
    // struct List* head = (struct List*) malloc(sizeof(struct List)); //for c
    list head = new (struct List); // for c++
    head->next = NULL;
    head->size = 0;
    return head;
}

void addLast(list head, int value){
    nodeptr tail = head->next;
    if(tail == NULL){
        nodeptr newNode = createNode(value);
        head->next = newNode;
        head->size++;
        return;
    }
    while(tail->next != NULL){
        tail = tail->next;
    }
    nodeptr newNode = createNode(value);
    tail->next = newNode;
    head->size++;
}

void display(list head){
     nodeptr tail = head->next;
     if(tail == NULL){
        cout << "The list is empty!" << endl; return;
     }
    while(tail != NULL){
        cout<<tail->value<<" ";
        tail = tail->next;
    }
    cout<<endl;
}


void addFirst(list head, int value){
     nodeptr newNode = createNode(value);
     newNode->next = head->next;
     head->next = newNode;
     head->size++;
}
void add(list head, int value,int index){
    nodeptr tail = head->next;

    int i = 0;
    if(index == 0) {addFirst(head, value); return;}
    if(index > head->size){
        addLast(head,value);
        return;
    }
    head->size++;
    while(i<index-1){
        tail = tail->next;
        i++;
    }

    nodeptr newNode = createNode(value);
    newNode->next = tail->next;
    tail->next = newNode;
}
int main(){
    list myList = createList();
    
    display(myList);
    addLast(myList,5);
    display(myList);
    addLast(myList,6);
    display(myList);
    addLast(myList,7);
    display(myList);
    
    addFirst(myList,44);
    display(myList);

    add(myList,78,5); 
    display(myList);

    addFirst(myList,51);
    display(myList);

    add(myList,78,2);
    display(myList);

    cout<<myList->size<<endl;
   
    return 0;
}
