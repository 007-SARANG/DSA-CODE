#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data = v; left = right = NULL; }
};

Node* insertNode(Node* root, int key){
    if(!root) return new Node(key);
    if(key < root->data) root->left = insertNode(root->left, key);
    else if(key > root->data) root->right = insertNode(root->right, key);
    return root;
}

Node* findMin(Node* root){
    while(root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key){
    if(!root) return root;

    if(key < root->data) root->left = deleteNode(root->left, key);
    else if(key > root->data) root->right = deleteNode(root->right, key);
    else {
        if(!root->left && !root->right) return NULL;
        else if(!root->left){
            Node* t = root->right;
            return t;
        }
        else if(!root->right){
            Node* t = root->left;
            return t;
        }
        Node* t = findMin(root->right);
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l > r ? l : r);
}

int minDepth(Node* root){
    if(!root) return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if(!root->left || !root->right) return 1 + l + r;
    return 1 + (l < r ? l : r);
}

int main(){
    Node* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    root = deleteNode(root, 30);

    cout << "Max Depth: " << maxDepth(root) << "\n";
    cout << "Min Depth: " << minDepth(root) << "\n";

    return 0;
