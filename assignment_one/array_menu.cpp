#include <iostream>
using namespace std;

#define MAX_SIZE 100

int arr[MAX_SIZE];
int n = 0;

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX_SIZE) {
        cout << "Max size exceeded!\n";
        n = 0;
        return;
    }
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display() {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    if (n == MAX_SIZE) {
        cout << "Array is full!\n";
        return;
    }
    int pos, val;
    cout << "Enter position to insert (0-based): ";
    cin >> pos;
    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    cout << "Enter value to insert: ";
    cin >> val;
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;
    cout << "Inserted successfully.\n";
}

void deleteElement() {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    int pos;
    cout << "Enter position to delete (0-based): ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    cout << "Deleted successfully.\n";
}

void linearSearch() {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    int key, found = 0;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at position: " << i << endl;
            found = 1;
        }
    }
    if (!found) cout << "Not found!\n";
}

int main() {
    int choice;
    while (1) {
        cout << "\n-----MENU-----\n";
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
    return 0;
}
