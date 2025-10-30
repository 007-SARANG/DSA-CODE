#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int findMiddle() {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    int mid = length / 2;
    temp = head;
    for (int i = 0; i < mid; i++) {
        temp = temp->next;
    }
    return temp->data;
}

int main() {
    int n, value;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(value);
    }

    if (head == NULL) {
        cout << "List is empty" << endl;
    } else {
        cout << "Middle element: " << findMiddle() << endl;
    }

    return 0;
}