#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data=v; left=right=NULL; }
};

int searchPos(int inorder[], int start, int end, int val){
    for(int i=start;i<=end;i++){
        if(inorder[i] == val) return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int postorder[], int start, int end, int &index){
    if(start > end) return NULL;

    Node* root = new Node(postorder[index--]);

    if(start == end) return root;

    int pos = searchPos(inorder, start, end, root->data);

    root->right = buildTree(inorder, postorder, pos+1, end, index);
    root->left  = buildTree(inorder, postorder, start, pos-1, index);

    return root;
}

void printPreorder(Node* root){
    if(!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    int inorder[]   = {4,2,5,1,6,3};
    int postorder[] = {4,5,2,6,3,1};
    int n = 6;
    int index = n-1;

    Node* root = buildTree(inorder, postorder, 0, n-1, index);

    printPreorder(root);  // just to verify
    return 0;
}
