#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    Node* head = new Node();
    head->data = 2;
    head->next = new Node();
    head->next->data = 4;
    head->next->next = new Node();
    head->next->next->data = 6;
    head->next->next->next = new Node();
    head->next->next->next->data = 7;
    head->next->next->next->next = new Node();
    head->next->next->next->next->data = 5;

    cout << "List: 2->4->6->7->5" << endl;
    
    head->next->next->next->next->next = head;

    if (isCircular(head)) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }
    
    Node* head2 = new Node();
    head2->data = 1;
    head2->next = new Node();
    head2->next->data = 2;
    head2->next->next = NULL;

    cout << "\nList: 1->2->NULL" << endl;
    if (isCircular(head2)) {
        cout << "Output: True" << endl;
    } else {
        cout << "Output: False" << endl;
    }

    return 0;
}