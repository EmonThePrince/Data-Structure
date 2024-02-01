/*
    This code is about a linked list that has the 
    ability to shift itself into header linked list.
    Insertion deletion and searching can be performed 
    with this linked list.

    -- Saim Ahmed Emon 

*/

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
    //int value; //if header list
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

int deleteFirst(list head){
    if(head->size == 0) {
        printf("List is empty!");
        return -1;
    }
    if(head->size == 1){
        nodeptr removedNode = head->next;
        head->next = NULL;
        head->size--;
        return removedNode->value;
    }
    head->size--;
    nodeptr removedNode = head->next;
    head->next = head->next->next;
    return removedNode->value;
}

int deleteNode(list head, int index){
    nodeptr tail = head->next;
    int i = 0;
    if(index == 0) {return deleteFirst(head);}
    if(index >= head->size){
        printf("Enter a valid index.\n");
        return -1;
    }
    if(head->size <= 0) {
        printf("List is empty!\n");
        return -1;
    }
    if(head->size == 1){
        nodeptr removedNode = head->next;
        head->next = NULL;
        head->size--;
        return removedNode->value;
    }
    head->size--;
    while(i<index-1){
        tail = tail->next;
        i++;
    }
    nodeptr removedNode = tail->next;
    tail->next = tail->next->next;
    return removedNode->value;
}

int deleteLast(list head){
    return deleteNode(head, head->size-1);
}

int searchNode(list head, int item){
    int index = 0;
    nodeptr tail = head->next;
    if(tail == NULL){
        cout << "The list is empty!" << endl; return -1;
     }
    while(tail != NULL){
        //processing
        if(tail->value == item) return index;
        tail = tail->next;
        index++;
    }
    return -1;
}

int main(){
    list myList = createList();
    
    //display(myList);
    
    addLast(myList,5);
    addLast(myList,6);
    addLast(myList,7);
    addFirst(myList,44);
    add(myList,78,5); 
    addFirst(myList,51);
    add(myList,78,2);
    display(myList);

    deleteFirst(myList);;
    deleteLast(myList);
    deleteFirst(myList);
    deleteFirst(myList);
    deleteLast(myList);
    deleteFirst(myList);
    display(myList);
    
    //cout<<searchNode(myList, 14)<<endl;
    return 0;
}
