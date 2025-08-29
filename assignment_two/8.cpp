#include <iostream>
using namespace std;

void sort_ints(int a[], int n){
    for(int i=0;i<n-1;++i) for(int j=0;j<n-1-i;++j) if(a[j]>a[j+1]){ int t=a[j]; a[j]=a[j+1]; a[j+1]=t; }
}

int countDistinct(int a[], int n){
    if(n==0) return 0;
    sort_ints(a,n);
    int cnt = 1;
    for(int i=1;i<n;++i) if(a[i]!=a[i-1]) ++cnt;
    return cnt;
}

int main(){
    int a[] = {1,2,2,3,4,4,4,5};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Array: "; for(int i=0;i<n;++i) cout << a[i] << " "; cout << '\n';
    cout << "Distinct count: " << countDistinct(a,n) << '\n';
    return 0;
}
