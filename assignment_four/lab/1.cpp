#include <iostream>
using namespace std;

const int SIZE = 5;

class Queue {
	int arr[SIZE];
	int R,F;
	
public:
	Queue(){
		F = -1;
		R = -1;
	}
	
	bool isEmpty() {
		return F == -1;
	}
	bool isFull(){
		return R == SIZE-1;
	}
	void enqueue(int val){
		if(isFull()) {
			cout << "Queue is Full!" << endl;
			return;
		}
		if(isEmpty()){
			F = 0;
		}
		R++;
		arr[R] = val;
		cout<<val<<" Added" << endl;
	}
	void dequeue(){
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
			return;
		}
		cout<< arr[F]<<" removed"<<endl;
		if (F==R){
			F = R = -1;
		}
		else F++;
	}
	void peek(){
		if(isEmpty()){
			cout<<"Queue is Empty" << endl;
		}
		else{
			cout<<"Front Element: "<<arr[F]<<endl;
		}
	}
	void display(){
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
		}
		cout<<"Queue Elements: ";
		for (int i = F; i<=R; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	Queue q;
	int choice,value;
	
	do{
		cout<<"\nMenu:\n1. Add\n2. Remove\n3. Peek\n4. Display\n5. Exit\nChoose: ";
		cin>>choice;
	switch (choice){
		case 1:
			cout<<"Enter Value: ";
			cin>>value;
			q.enqueue(value);
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			q.peek();
			break;
		case 4:
			q.display();
			break;
		case 5:
			cout<<"Bye"<<endl;
			break;
		default:
			cout<<"Invalid Choice"<<endl;
	}
}
	while(choice!=5);
	return 0;
}
