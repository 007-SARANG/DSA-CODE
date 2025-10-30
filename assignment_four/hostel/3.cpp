#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueueUsingStack(queue<int>& q) {
    

    stack<int> st;
    int half = q.size() / 2;


    for (int i = 0; i < half; i++) {
        st.push(q.front());
        q.pop();
    }

   
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

   
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }

   
    for (int i = 0; i < half; i++) {
        st.push(q.front());
        q.pop();
    }

    
    while (!st.empty()) {
        q.push(st.top());   
        st.pop();

        q.push(q.front());  
        q.pop();
    }
}



void interleaveQueueUsingQueue(queue<int>& q) {
    int n = q.size();

    queue<int> firstHalf;
    int half = n / 2;

    
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q,qu;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
        qu.push(arr[i]);
    }

    interleaveQueueUsingStack(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout<<endl;
    interleaveQueueUsingStack(qu);
     while (!qu.empty()) {
        cout << qu.front() << " ";
        qu.pop();
    }

    return 0;
}