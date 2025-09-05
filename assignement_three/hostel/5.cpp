#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class Stack {
private:
    int data[100];
    int top;
    
public:
    Stack() {
        top = -1;
    }
    
    void push(int value) {
        if (top < 99) {
            data[++top] = value;
        }
    }
    
    int pop() {
        if (top >= 0) {
            return data[top--];
        }
        return 0;
    }
    
    bool isEmpty() {
        return top == -1;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': {
            int result = 1;
            for (int i = 0; i < operand2; i++) {
                result *= operand1;
            }
            return result;
        }
        default: return 0;
    }
}

int evaluatePostfix(char postfix[]) {
    Stack stack;
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];
        
        if (isdigit(current)) {
            stack.push(current - '0');
        }
        else if (isOperator(current)) {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            
            int result = performOperation(operand1, operand2, current);
            stack.push(result);
        }
    }
    
    return stack.pop();
}

int main() {
    char postfix[100];
    
    cout << "Enter postfix expression: ";
    cin >> postfix;
    
    int result = evaluatePostfix(postfix);
    
    cout << "Result: " << result << endl;
    
    return 0;
}
