#include <iostream>
using namespace std;

int missingLinear(int a[], int size, int n){
    for(int i = 0; i < size; ++i){
        if(a[i] != i+1) return i+1;
    }
    return n;
}

int missingBinary(int a[], int size, int n){
    int l = 0, r = size-1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(a[mid] == mid+1) l = mid+1;
        else r = mid-1;
    }
    return l+1;
}

int main(){
    int a[] = {1,2,3,4,6,7,8};
    int size = sizeof(a)/sizeof(a[0]);
    int n = 8;
    cout << "Array: "; for(int i=0;i<size;++i) cout << a[i] << " "; cout << '\n';
    cout << "Missing (linear): " << missingLinear(a,size,n) << '\n';
    cout << "Missing (binary): " << missingBinary(a,size,n) << '\n';
    return 0;
}
