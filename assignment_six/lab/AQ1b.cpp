#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
public:
    Node* last;

    CircularLinkedList() {
        last = NULL;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node();
        newNode->data = val;

        if (last == NULL) {
            last = newNode;
            newNode->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
        cout << val << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;

        if (last == NULL) {
            last = newNode;
            newNode->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        cout << val << " inserted at the end." << endl;
    }

    void insertAfter(int nodeVal, int val) {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next;
        do {
            if (temp->data == nodeVal) {
                Node* newNode = new Node();
                newNode->data = val;
                newNode->next = temp->next;
                temp->next = newNode;
                if (temp == last) {
                    last = newNode;
                }
                cout << val << " inserted after " << nodeVal << "." << endl;
                return;
            }
            temp = temp->next;
        } while (temp != last->next);

        cout << "Node " << nodeVal << " not found." << endl;
    }

    void insertBefore(int nodeVal, int val) {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* head = last->next;
        if (head->data == nodeVal) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        Node* prev = last;
        do {
            if (temp->data == nodeVal) {
                Node* newNode = new Node();
                newNode->data = val;
                newNode->next = temp;
                prev->next = newNode;
                cout << val << " inserted before " << nodeVal << "." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Node " << nodeVal << " not found." << endl;
    }

    void deleteNode(int val) {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* head = last->next;
        Node* curr = head;
        Node* prev = last;

        do {
            if (curr->data == val) {
                if (curr == head && curr == last) {
                    last = NULL;
                } else if (curr == head) {
                    last->next = head->next;
                } else if (curr == last) {
                    prev->next = head;
                    last = prev;
                } else {
                    prev->next = curr->next;
                }
                
                delete curr;
                cout << "Node " << val << " deleted." << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Node " << val << " not found." << endl;
    }

    void searchNode(int val) {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next;
        int pos = 1;
        do {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);

        cout << "Node " << val << " not found." << endl;
    }

    void display() {
        if (last == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next;
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(back to " << last->next->data << ")" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, val, nodeVal;

    do {
        cout << "\n--- Circular Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After a Node" << endl;
        cout << "4. Insert Before a Node" << endl;
        cout << "5. Delete a Specific Node" << endl;
        cout << "6. Search for a Node" << endl;
        cout << "7. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                cll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                cll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value of the node to insert after: ";
                cin >> nodeVal;
                cout << "Enter value to insert: ";
                cin >> val;
                cll.insertAfter(nodeVal, val);
                break;
            case 4:
                cout << "Enter value of the node to insert before: ";
                cin >> nodeVal;
                cout << "Enter value to insert: ";
                cin >> val;
                cll.insertBefore(nodeVal, val);
                break;
            case 5:
                cout << "Enter value of the node to delete: ";
                cin >> val;
                cll.deleteNode(val);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                cll.searchNode(val);
                break;
            case 7:
                cll.display();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}