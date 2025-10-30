#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        cout << val << " inserted at the beginning." << endl;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            cout << val << " inserted as head." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        cout << val << " inserted at the end." << endl;
    }

    void insertAfter(int nodeVal, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != nodeVal) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node " << nodeVal << " not found." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;

        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }
        cout << val << " inserted after " << nodeVal << "." << endl;
    }

    void insertBefore(int nodeVal, int val) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == nodeVal) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != nodeVal) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node " << nodeVal << " not found." << endl;
            return;
        }

        Node* newNode = new Node();
        newNode->data = val;
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
        cout << val << " inserted before " << nodeVal << "." << endl;
    }

    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node " << val << " not found." << endl;
            return;
        }

        if (temp == head) {
            head = temp->next;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Node " << val << " deleted." << endl;
    }

    void searchNode(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << "." << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << val << " not found in the list." << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "List (forward): NULL <=> ";
        while (temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, val, nodeVal;

    do {
        cout << "\n--- Doubly Linked List Menu ---" << endl;
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
                dll.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> val;
                dll.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value of the node to insert after: ";
                cin >> nodeVal;
                cout << "Enter value to insert: ";
                cin >> val;
                dll.insertAfter(nodeVal, val);
                break;
            case 4:
                cout << "Enter value of the node to insert before: ";
                cin >> nodeVal;
                cout << "Enter value to insert: ";
                cin >> val;
                dll.insertBefore(nodeVal, val);
                break;
            case 5:
                cout << "Enter value of the node to delete: ";
                cin >> val;
                dll.deleteNode(val);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                dll.searchNode(val);
                break;
            case 7:
                dll.display();
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