#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int sz = q.size();
        q.push(x);

      
        for (int i = 0; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

class StackTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

       
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        cout << "Popped: " << q1.front() << endl;
        q1.pop();

        
        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topVal = q1.front();
        q2.push(topVal); 
        q1.pop();
        swap(q1, q2);
        return topVal;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top: " << s.top() << endl;
    s.pop();
    s.pop(); 

    StackTwoQueues s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Top: " << s1.top() << endl;
    s1.pop();
    cout << "Top: " << s1.top() << endl;
    s1.pop();
    cout << "Top: " << s1.top() << endl;
    s1.pop();
    s1.pop();


    return 0;
}