#include <iostream>
using namespace std;

#define MAX_SIZE 100

// a. Reverse the elements of an array
void reverseArray() {
    int arr[MAX_SIZE], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Reversed array: ";
    for (int i = n - 1; i >= 0; i--) cout << arr[i] << " ";
    cout << endl;
}

// b. Matrix multiplication
void matrixMultiplication() {
    int a[10][10], b[10][10], c[10][10] = {0};
    int n1, m1, n2, m2;
    cout << "Enter rows and columns of first matrix: ";
    cin >> n1 >> m1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> n2 >> m2;
    if (m1 != n2) {
        cout << "Matrix multiplication not possible!\n";
        return;
    }
    cout << "Enter first matrix:\n";
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            cin >> a[i][j];
    cout << "Enter second matrix:\n";
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < m2; j++)
            cin >> b[i][j];
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
            for (int k = 0; k < m1; k++)
                c[i][j] += a[i][k] * b[k][j];
    cout << "Resultant matrix:\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

// c. Transpose of a matrix
void transposeMatrix() {
    int a[10][10], t[10][10];
    int n, m;
    cout << "Enter rows and columns of matrix: ";
    cin >> n >> m;
    cout << "Enter matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            t[j][i] = a[i][j];
    cout << "Transpose:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int choice;
    while (1) {
        cout << "\n1. Reverse Array\n2. Matrix Multiplication\n3. Transpose Matrix\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: reverseArray(); break;
            case 2: matrixMultiplication(); break;
            case 3: transposeMatrix(); break;
            case 4: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
    return 0;
}
