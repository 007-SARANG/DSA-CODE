#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data=v; left=right=NULL; }
};

int searchPos(int inorder[], int start, int end, int val){
    for(int i=start; i<=end; i++){
        if(inorder[i] == val) return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end, int &index){
    if(start > end) return NULL;

    Node* root = new Node(preorder[index++]);

    if(start == end) return root;

    int pos = searchPos(inorder, start, end, root->data);

    root->left  = buildTree(preorder, inorder, start, pos-1, index);
    root->right = buildTree(preorder, inorder, pos+1, end, index);

    return root;
}

void printPostorder(Node* root){
    if(!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main(){
    int preorder[] = {1,2,4,5,3,6};
    int inorder[]  = {4,2,5,1,3,6};
    int n = 6;
    int index = 0;

    Node* root = buildTree(preorder, inorder, 0, n-1, index);

    printPostorder(root);  // Just to show tree is constructed correctly
    return 0;
}
