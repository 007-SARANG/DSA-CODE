#include<iostream>
using namespace std;

class Stack{
    int arr[100];
    int top;
    int size;

public:
    Stack(int n){
        size = n;
        top = -1;
    }
bool isEmpty(){
    return top == -1;
}
bool isFull(){
    return top ==size -1;
}
void push(int x){
    if(isFull())
        cout<<"Stack Overflow!";
    else
    arr[++top]=x;
}
void pop(){
    if (isEmpty())
        cout<<"Stack Underflow";
    else
        cout<<"Top element "<<arr[top--]<<endl;
}
void peek(){
    if(isEmpty())
        cout<<"Stack is Empty";
    else
        cout<<"Top Element: "<<arr[top]<<endl;
}
void display(){
    if(isEmpty()){
    cout<<"Stack is Empty";
    return;}
    cout<<"Stack: ";
    for(int i =top;i>=0;i--){
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}
};

int main(){
    int n;
    cout<<"Enter stack size: ";
    cin>>n;

    Stack s(n);
    int choice,val;
    while(true){
        cout<<"\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\nEnter Choice: ";
        cin>>choice;
        switch(choice){
            case 1:cout<<"Enter value: "; cin>>val;
            s.push(val); break;
            
            case 2: s.pop(); break;
            case 3: s.display(); break;
            case 4: s.peek(); break;
            case 5: return 0;
            default: cout<<"Invalid Choice!\n";
        }
    }
}