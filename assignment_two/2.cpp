#include <iostream>
using namespace std;

void bubbleSort(int a[], int n){
    for(int i = 0; i < n-1; ++i){
        bool swapped = false;
        for(int j = 0; j < n-1-i; ++j){
            if(a[j] > a[j+1]){ int tmp = a[j]; a[j] = a[j+1]; a[j+1] = tmp; swapped = true; }
        }
        if(!swapped) break;
    }
}

int main(){
    int a[] = {64,34,25,12,22,11,90};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Unsorted: "; for(int i=0;i<n;++i) cout << a[i] << " "; cout << '\n';
    bubbleSort(a, n);
    cout << "Sorted: "; for(int i=0;i<n;++i) cout << a[i] << " "; cout << '\n';
    return 0;
}
