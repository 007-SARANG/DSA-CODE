#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data=v; left=right=NULL; }
};

bool isBSTUtil(Node* root, int minVal, int maxVal){
    if(!root) return true;
    if(root->data <= minVal || root->data >= maxVal) return false;
    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root){
    return isBSTUtil(root, -1000000, 1000000);
}

int main(){
    Node* root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(70);

    if(isBST(root)) cout << "Tree is BST\n";
    else cout << "Tree is NOT BST\n";

    return 0;
}
