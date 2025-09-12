#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList{
    public:
    Node* head = nullptr;

    void InsertBeg(int value){
        Node*newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void InsertEnd(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }
        else {
            Node* current=head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void InsertfterValue(int existingValue, int newValue){
        Node* newNode = new Node(newValue);
        Node* current = head;

        if(head==nullptr){
            head==newNode;
            return;
        }
        else{
            while (current != nullptr && current ->data != existingValue){
                current = current->next;
            }
            if(current == nullptr){
                cout<<"Value not Found"<<endl;
            }
            else{
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }
    void DeleteBeg(){
        if(head == nullptr){
            cout<<"Linked List is Empty"<<endl;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void DeleteEnd(){
        if(head==nullptr){
            cout<<"Linked List is Empty"<<endl;
        }
        else if(head->next==nullptr){
            delete head;
            head = nullptr;
        }
        else{
            Node* current = head;
            while(current->next->next != nullptr){
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }
    void deleteNodewithValue(int value){
    	if(head==nullptr){
    		cout<<"List is Empty"<<endl;
    		return;
		}
		Node* temp = head;
		Node* pre = nullptr;
		while(temp!=nullptr && temp->data !=value){
			pre = temp;
			temp = temp->next;
		}
		if(temp==nullptr){
			cout<<"Element Not Found"<<endl;
			return;
		}
	}
};
