#include <iostream>
using namespace std;

long long mergeCount(int a[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = new int[n1];
    int *R = new int[n2];
    for(int i=0;i<n1;++i) L[i]=a[l+i];
    for(int j=0;j<n2;++j) R[j]=a[m+1+j];
    int i=0,j=0,k=l;
    long long inv=0;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]) a[k++] = L[i++];
        else { a[k++] = R[j++]; inv += (n1 - i); }
    }
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];
    delete[] L; delete[] R;
    return inv;
}

long long countInversions(int a[], int l, int r){
    long long inv=0;
    if(l<r){
        int m = l + (r-l)/2;
        inv += countInversions(a,l,m);
        inv += countInversions(a,m+1,r);
        inv += mergeCount(a,l,m,r);
    }
    return inv;
}

int main(){
    int a[] = {2,4,1,3,5};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Array: "; for(int i=0;i<n;++i) cout << a[i] << " "; cout << '\n';
    int *b = new int[n]; for(int i=0;i<n;++i) b[i]=a[i];
    long long inv = countInversions(b,0,n-1);
    cout << "Inversions: " << inv << '\n';
    delete[] b;
    return 0;
}
