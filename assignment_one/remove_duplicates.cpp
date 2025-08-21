#include <iostream>
using namespace std;

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE], n;
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX_SIZE) {
        cout << "Max size exceeded!\n";
        return 1;
    }
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Remove duplicates
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
            } else {
                j++;
            }
        }
    }
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
