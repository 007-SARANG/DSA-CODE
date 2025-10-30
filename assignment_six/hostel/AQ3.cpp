#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* newNode = new Node();
    newNode->data = new_data;
    newNode->next = *head_ref;
    newNode->prev = NULL;
    if (*head_ref != NULL) {
        (*head_ref)->prev = newNode;
    }
    *head_ref = newNode;
}

int getSize(Node* head) {
    int size = 0;
    Node* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

int main() {
    Node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Doubly Linked List: 1 <=> 2 <=> 3 <=> 4 <=> 5" << endl;
    cout << "Size of DLL: " << getSize(head) << endl;

    return 0;
}