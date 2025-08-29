#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str;
    cout<<"Enter a string: ";
    cin>>str;
    stack<char>s;
    for(char c:str){
        s.push(c);
    }
    cout<<"Reversed String: ";
    while(s.empty()==false){
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    return 0;
}