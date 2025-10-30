#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** head_ref, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head_ref;

    if (*head_ref != NULL) {
        Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        newNode->next = newNode;
    }
    *head_ref = newNode;
}

int getSize(Node* head) {
    if (head == NULL) {
        return 0;
    }

    int size = 0;
    Node* temp = head;
    do {
        size++;
        temp = temp->next;
    } while (temp != head);
    
    return size;
}

int main() {
    Node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Circular Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 1" << endl;
    cout << "Size of CLL: " << getSize(head) << endl;

    return 0;
}