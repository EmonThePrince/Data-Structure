#include <iostream>

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

int main() {
    int numVertices = 5; 

    // Adding edges
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(3, 4);

    // Print adjacency list
    printAdjacencyList(numVertices);

    cleanup(numVertices);

    return 0;
}
