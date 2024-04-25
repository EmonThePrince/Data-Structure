#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 100;

struct StringStack {
    int arr[MAX_SIZE];
    int top;
};

void initializeStack(StringStack& stack) {
    stack.top = -1;
}

bool isEmpty(const StringStack& stack) {
    return stack.top == -1;
}

bool isFull(const StringStack& stack) {
    return stack.top == MAX_SIZE - 1;
}

void push(StringStack& stack, const int& item) {
    if (isFull(stack)) {
        std::cout << "Stack Overflow\n";
        return;
    }
    stack.arr[++stack.top] = item;
}

int pop(StringStack& stack) {
    if (isEmpty(stack)) {
        std::cout << "Stack Underflow\n";
        return -1;
    }
    return stack.arr[stack.top--];
}

int peek(const StringStack& stack) {
    if (isEmpty(stack)) {
        std::cout << "Stack is empty\n";
        return -1;
    }
    return stack.arr[stack.top];
}

void display(const StringStack& stack) {
    if (isEmpty(stack)) {
        std::cout << "Stack is empty\n";
        return;
    }
    std::cout << "Stack elements:\n";
    for (int i = stack.top; i >= 0; i--) {
        std::cout << stack.arr[i] << endl;
    }
}

const int MAX_VERTICES = 100; 
struct Node {
    int vertex;
    Node* next;
};

Node* adjLists[MAX_VERTICES] = {nullptr};

void addEdge(int src, int dest) {

    Node* newNode = new Node;
    newNode->vertex = dest;
    newNode->next = adjLists[src];
    adjLists[src] = newNode;

    newNode = new Node;
    newNode->vertex = src;
    newNode->next = adjLists[dest];
    adjLists[dest] = newNode;
}

// Print the adjacency list
void printAdjacencyList(int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Adjacency list for vertex " << i << ": ";
        Node* current = adjLists[i];
        while (current) {
            std::cout << current->vertex << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

void cleanup(int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        Node* current = adjLists[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

void DFS(int rootNode, bool vis[]){
    StringStack stack;
    initializeStack(stack);

    push(stack, rootNode);
    while(!isEmpty(stack)){
        int curr = pop(stack);
        if(!vis[curr]){
            vis[curr] = true;
            cout<<curr<<" ";
        }

        Node* current = adjLists[curr];
        while (current) {
            if(!vis[current->vertex]){
                push(stack,current->vertex);
            }
            current = current->next;
        }
        
    }


}

int main() {
    int numVertices = 5; 
    bool vis[numVertices] = {0};

    // Adding edges
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(3, 4);

    // Print adjacency list
    printAdjacencyList(numVertices);

    //dfs view for 1 node
    cout<<"dfs for 1:"<<endl;
    DFS(1,vis);

    return 0;
}