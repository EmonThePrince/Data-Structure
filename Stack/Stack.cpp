#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 100;

struct StringStack {
    string arr[MAX_SIZE];
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

void push(StringStack& stack, const string& item) {
    if (isFull(stack)) {
        std::cout << "Stack Overflow\n";
        return;
    }
    stack.arr[++stack.top] = item;
}

string pop(StringStack& stack) {
    if (isEmpty(stack)) {
        std::cout << "Stack Underflow\n";
        return "";
    }
    return stack.arr[stack.top--];
}

string peek(const StringStack& stack) {
    if (isEmpty(stack)) {
        std::cout << "Stack is empty\n";
        return "";
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

int main() {
    StringStack stack;
    initializeStack(stack);

    push(stack, "Hello");
    push(stack, "World");
    push(stack, "!");

    display(stack); 

    cout << "Popped: " << pop(stack) << endl;

    display(stack); 

    cout << "Top element: " << peek(stack) << endl; 

    return 0;
}