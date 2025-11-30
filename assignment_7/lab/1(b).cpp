#include <iostream>
using namespace std;

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main(){
    int a[]={9,4,2,7,1}, n=5;
    insertionSort(a,n);
    for(int x:a) cout<<x<<" ";
}
