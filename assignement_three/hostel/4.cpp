#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Stack {
private:
    char data[100];
    int top;
    
public:
    Stack() {
        top = -1;
    }
    
    void push(char c) {
        if (top < 99) {
            data[++top] = c;
        }
    }
    
    char pop() {
        if (top >= 0) {
            return data[top--];
        }
        return '\0';
    }
    
    char peek() {
        if (top >= 0) {
            return data[top];
        }
        return '\0';
    }
    
    bool isEmpty() {
        return top == -1;
    }
};

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isRightAssociative(char op) {
    return op == '^';
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];
        
        if (isalnum(current)) {
            postfix[j++] = current;
        }
        else if (current == '(') {
            stack.push(current);
        }
        else if (current == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix[j++] = stack.pop();
            }
            stack.pop();
        }
        else if (isOperator(current)) {
            while (!stack.isEmpty() && stack.peek() != '(' &&
                   ((getPrecedence(stack.peek()) > getPrecedence(current)) ||
                    (getPrecedence(stack.peek()) == getPrecedence(current) && !isRightAssociative(current)))) {
                postfix[j++] = stack.pop();
            }
            stack.push(current);
        }
    }
    
    while (!stack.isEmpty()) {
        postfix[j++] = stack.pop();
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];
    
    cout << "Enter infix expression: ";
    cin >> infix;
    
    infixToPostfix(infix, postfix);
    
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}
