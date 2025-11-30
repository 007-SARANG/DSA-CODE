#include <iostream>
using namespace std;

int partitionArr(int a[], int low, int high){
    int pivot=a[high], i=low-1;
    for(int j=low;j<high;j++)
        if(a[j]<pivot){
            i++; 
            swap(a[i],a[j]);
        }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high){
    if(low<high){
        int pi=partitionArr(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

int main(){
    int a[]={8,4,7,3,1}, n=5;
    quickSort(a,0,n-1);
    for(int x:a) cout<<x<<" ";
}
