#include<iostream>
using namespace std;

class ArrayQueue {
    int start;
    int *arr;
    int currsize, maxsize;
    int end;

   public:
    ArrayQueue() {
        maxsize = 2;
        arr = new int[maxsize];
        start = -1;
        end = -1;
        currsize = 0;
    }

    void enqueue(int x) {
        if ((end-start+1) == maxsize) return;

        if (start == -1) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % maxsize;
        }

        arr[end] = x;
    }

    void dequeue() {
        if (start == -1) return ;
         if (start == end) {
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1) % maxsize;
        }
        
    }

    int peek() {
        if (start == -1) {
            return -1;
        }
        return arr[start];
    }

    bool isEmpty() { return (start == -1); }
    bool isFull() { return ((end+start+1) == maxsize); }
};

int main(){
    ArrayQueue q;
    q.enqueue(7);
    cout<<q.peek()<<endl;
    q.enqueue(9);
    q.enqueue(10);
    cout<<q.peek()<<endl;
    cout<<q.isEmpty()<<endl;
    q.dequeue();
    q.enqueue(1);
    cout<<q.isFull()<<endl;
    cout<<q.isEmpty()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.isEmpty()<<endl;
    
    
    return 0;
}