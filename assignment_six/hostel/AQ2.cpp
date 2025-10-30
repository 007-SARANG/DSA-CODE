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

void displayList(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    
    cout << head->data << endl;
}

int main() {
    Node* head = NULL;
    
    push(&head, 60);
    push(&head, 80);
    push(&head, 40);
    push(&head, 100);
    push(&head, 20);

    cout << "Input: 20->100->40->80->60" << endl;
    cout << "Output: ";
    displayList(head);

    return 0;
}