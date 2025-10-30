#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

void push(Node** head_ref, char new_data) {
    Node* newNode = new Node();
    newNode->data = new_data;
    newNode->next = *head_ref;
    newNode->prev = NULL;
    if (*head_ref != NULL) {
        (*head_ref)->prev = newNode;
    }
    *head_ref = newNode;
}

bool isPalindrome(Node* head) {
    if (head == NULL) {
        return true;
    }

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* left = head;
    Node* right = tail;

    while (left != right && left->prev != right) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->prev;
    }
    
    return true;
}

int main() {
    Node* head = NULL;
    push(&head, 'L');
    push(&head, 'E');
    push(&head, 'V');
    push(&head, 'E');
    push(&head, 'L');

    cout << "List: L <=> E <=> V <=> E <=> L" << endl;
    if (isPalindrome(head)) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }

    Node* head2 = NULL;
    push(&head2, 'H');
    push(&head2, 'E');
    push(&head2, 'L');
    push(&head2, 'L');
    push(&head2, 'O');

    cout << "\nList: O <=> L <=> L <=> E <=> H" << endl;
    if (isPalindrome(head2)) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }

    return 0;
}