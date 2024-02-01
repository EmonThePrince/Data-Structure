# Data Structure
## Linked List
This code is about a linked list that has the ability to shift itself into header linked list.Insertion deletion and searching can be performed with this linked list.
<br/>
<br/>

This part is about the start pointer and the normal node that contain the actual information.
```c++
struct Node //normal Node 
{
    int value; // Information
    struct Node* next; // Pointer to next node
};

struct List
{
    //int value; //If header list. The value here does not matter
    int size; // List size (optional)
    struct Node* next; // Pointer to the first node(that has information) of the list
};

```

<br/>
<br/>

Function <code><b>createNode</b></code> is used to create a node it takes a value that is stored in the information part.
<br/>
<br/>
Function <code><b>createList</b></code> is used to create a Linked list header pointer it is same as the start pointer that has been discussed in the class.
<br/>
<br/>
Function <code><b>display</b></code> is used to display or print(on terminal) the whole linked list.
<br/>
<br/>
Function <code><b>searchNode</b></code> is used to search an item from the linked list. This function the returns an integer that indicates the index of the first occurance of the information(that is given as paramiter). 
If the information is not found than this function will return -1. The index follows the traditional array index (starts from zero). 
<br/>
<br/>
Function <code><b>addFirst</b></code>, <code><b>addLast</b></code> and <code><b>add</b></code> is used to add information(node) at the first, last or at any index of the linked list.
<br/>
<br/>
Function <code><b>deleteFirst</b></code>, <code><b>deleteLast</b></code> and <code><b>deleteNode</b></code> is used to delete information(node) at the first, last or at any index of the linked list.
