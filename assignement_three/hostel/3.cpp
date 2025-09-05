#include <iostream>
#include <cstring>
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
    
    bool isEmpty() {
        return top == -1;
    }
};

bool areMatching(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}

bool isBalanced(char expression[]) {
    Stack stack;
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];
        
        if (current == '(' || current == '[' || current == '{') {
            stack.push(current);
        }
        else if (current == ')' || current == ']' || current == '}') {
            if (stack.isEmpty()) {
                return false;
            }
            
            char lastOpen = stack.pop();
            if (!areMatching(lastOpen, current)) {
                return false;
            }
        }
    }
    
    return stack.isEmpty();
}

int main() {
    char expression[100];
    
    cout << "Enter expression: ";
    cin >> expression;
    
    if (isBalanced(expression)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    
    return 0;
}
