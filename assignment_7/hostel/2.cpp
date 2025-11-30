#include <iostream>
using namespace std;

void improvedSelection(int a[], int n){
    int start=0, end=n-1;
    while(start<end){
        int minIdx=start, maxIdx=start;
        for(int i=start;i<=end;i++){
            if(a[i]<a[minIdx]) minIdx=i;
            if(a[i]>a[maxIdx]) maxIdx=i;
        }
        swap(a[start], a[minIdx]);
        if(maxIdx==start) maxIdx=minIdx;
        swap(a[end], a[maxIdx]);
        start++; end--;
    }
}

int main(){
    int a[]={7,3,2,9,1,8}, n=6;
    improvedSelection(a,n);
    for(int x:a) cout<<x<<" ";
}
