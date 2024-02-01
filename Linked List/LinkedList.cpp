/*
    This code is about a linked list that has the 
    ability to shift itself into header linked list.
    Insertion deletion and searching can be performed 
    with this linked list.

    -- Saim Ahmed Emon 

*/

#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

struct List {
    int size;
    Node* next;
};

typedef Node* NodePtr;
typedef List* ListPtr;

NodePtr createNode(int value) {
    NodePtr newNode = new Node;
    newNode->next = nullptr;
    newNode->value = value;
    return newNode;
}

ListPtr createList() {
    ListPtr newList = new List;
    newList->next = nullptr;
    newList->size = 0;
    return newList;
}

void display(ListPtr head) {
    NodePtr current = head->next;
    if (current == nullptr) {
        cout << "The list is empty!" << endl;
        return;
    }
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void addLast(ListPtr head, int value) {
    NodePtr current = head->next;
    if (current == nullptr) {
        NodePtr newNode = createNode(value);
        head->next = newNode;
        head->size++;
        return;
    }
    while (current->next != nullptr) {
        current = current->next;
    }
    NodePtr newNode = createNode(value);
    current->next = newNode;
    head->size++;
}

void addFirst(ListPtr head, int value) {
    NodePtr newNode = createNode(value);
    newNode->next = head->next;
    head->next = newNode;
    head->size++;
}

void add(ListPtr head, int value, int index) {
    NodePtr current = head->next;
    int i = 0;
    if (index == 0) {
        addFirst(head, value);
        return;
    }
    if (index > head->size) {
        addLast(head, value);
        return;
    }
    head->size++;
    while (i < index - 1) {
        current = current->next;
        i++;
    }
    NodePtr newNode = createNode(value);
    newNode->next = current->next;
    current->next = newNode;
}

int deleteFirst(ListPtr head) {
    if (head->size == 0) {
        cout << "List is empty!" << endl;
        return -1;
    }
    if (head->size == 1) {
        NodePtr removedNode = head->next;
        head->next = nullptr;
        head->size--;
        int value = removedNode->value;
        delete removedNode;
        return value;
    }
    head->size--;
    NodePtr removedNode = head->next;
    head->next = head->next->next;
    int value = removedNode->value;
    delete removedNode;
    return value;
}

int deleteNode(ListPtr head, int index) {
    NodePtr current = head->next;
    int i = 0;
    if (index == 0) {
        return deleteFirst(head);
    }
    if (index >= head->size) {
        cout << "Enter a valid index." << endl;
        return -1;
    }
    if (head->size <= 0) {
        cout << "List is empty!" << endl;
        return -1;
    }
    if (head->size == 1) {
        NodePtr removedNode = head->next;
        head->next = nullptr;
        head->size--;
        int value = removedNode->value;
        delete removedNode;
        return value;
    }
    head->size--;
    while (i < index - 1) {
        current = current->next;
        i++;
    }
    NodePtr removedNode = current->next;
    current->next = current->next->next;
    int value = removedNode->value;
    delete removedNode;
    return value;
}

int deleteLast(ListPtr head) {
    return deleteNode(head, head->size - 1);
}

int searchNode(ListPtr head, int item) {
    int index = 0;
    NodePtr current = head->next;
    if (current == nullptr) {
        cout << "The list is empty!" << endl;
        return -1;
    }
    while (current != nullptr) {
        if (current->value == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

int main() {
    ListPtr myList = createList();

    addLast(myList, 5);
    addLast(myList, 6);
    addLast(myList, 7);
    addFirst(myList, 44);
    add(myList, 78, 5);
    addFirst(myList, 51);
    add(myList, 78, 2);
    display(myList);

    deleteFirst(myList);
    deleteLast(myList);
    deleteFirst(myList);
    deleteFirst(myList);
    deleteLast(myList);
    deleteFirst(myList);
    display(myList);

    return 0;
}
