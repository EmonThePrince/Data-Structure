#include<bits/stdc++.h>

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

bool isOperator(string infix, int index){
    return (infix[index] == '+') || (infix[index] == '-') || (infix[index] == '*')
    || (infix[index] == '/') || (infix[index] == '%') || (infix[index] == '^');  
}

bool isDigit(string infix, int index){
    return ((infix[index] >= '0') && (infix[index] <= '9'));
}

int getPrecedence(string infix){
    if(infix == "+" || infix == "-") return 1;
    else if(infix == "(") return 0;
    else if(infix == "*" || infix == "/" || infix == "%") return 2;
    return 3;
}
vector<string> infixToPostfix(string infix){
    vector<string> postfix;
    StringStack stack;
    initializeStack(stack);
    push(stack, "(");
    infix.push_back(')');
    int infixSize = infix.length();
    for(int i = 0; i < infixSize; i++){
        if(isDigit(infix, i)){
            string number;
            while(isDigit(infix,i)){
                number += infix[i];
                i++;
            }
            postfix.push_back(number);
        }
        if(infix[i] == '('){
            push(stack,"(");
        }
        string s = "";
        s = infix[i];
        if(isOperator(infix,i)){
            while(getPrecedence(peek(stack)) >= getPrecedence(s)){
                postfix.push_back(pop(stack));
            }
            push(stack, s);
           // display(stack);
        }
        if(s == ")"){
            while(peek(stack) != "("){
                postfix.push_back(pop(stack));
            }
            pop(stack);
        }
    }
    return postfix;
}

int evaluatePostfix(vector<string> &postfix){
    StringStack stack;
    initializeStack(stack);
    for(int i = 0; i < postfix.size(); i++){
        if(isOperator(postfix[i],0)){
            int b = stoi(pop(stack));
            int a = stoi(pop(stack));
            if(postfix[i] == "+") push(stack,to_string(a+b));
            if(postfix[i] == "*") push(stack,to_string(a*b));
            if(postfix[i] == "/") push(stack,to_string(a/b));
            if(postfix[i] == "-") push(stack,to_string(a-b));
            if(postfix[i] == "%") push(stack,to_string(a%b));
            if(postfix[i] == "^") push(stack,to_string(pow(a,b)));
        }
        else{
            push(stack,postfix[i]);
        }
    }
    int ans = stoi(pop(stack));
    return ans;
}

int main(){
    string infix = "(13*7) + 3 ";
    vector<string> postfix = infixToPostfix(infix);
    for(auto i: postfix){
        cout<<i<<" "; 
    }
    cout<<endl;
    int result = evaluatePostfix(postfix);
    cout<<result<<endl;
    return 0;
}