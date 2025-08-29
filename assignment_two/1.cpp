#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main(){
    int arr[] = {2,3,4,10,40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 10;
    cout << "Array: ";
    for(int i=0;i<n;++i) cout << arr[i] << " ";
    cout << "\nSearching for " << key << " using binary search...\n";
    int idx = binarySearch(arr, n, key);
    if(idx != -1) cout << "Found at index " << idx << " (0-based)\n";
    else cout << "Not found\n";
    return 0;
}
