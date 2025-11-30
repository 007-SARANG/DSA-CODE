#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v){ data=v; left=right=NULL; }
};

Node* searchRec(Node* root, int key){
    if(!root || root->data == key) return root;
    if(key < root->data) return searchRec(root->left, key);
    else return searchRec(root->right, key);
}

Node* searchNonRec(Node* root, int key){
    while(root){
        if(root->data == key) return root;
        if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

Node* findMin(Node* root){
    while(root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root){
    while(root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x){
    if(x->right) return findMin(x->right);
    Node* succ = NULL;
    while(root){
        if(x->data < root->data){
            succ = root;
            root = root->left;
        } else if(x->data > root->data){
            root = root->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x){
    if(x->left) return findMax(x->left);
    Node* pre = NULL;
    while(root){
        if(x->data > root->data){
            pre = root;
            root = root->right;
        } else if(x->data < root->data){
            root = root->left;
        } else break;
    }
    return pre;
}

int main(){
    Node* root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(70);

    Node* key = searchRec(root, 30);
    if(key) cout << "Found Rec: " << key->data << "\n";

    key = searchNonRec(root, 50);
    if(key) cout << "Found NonRec: " << key->data << "\n";

    cout << "Min: " << findMin(root)->data << "\n";
    cout << "Max: " << findMax(root)->data << "\n";

    Node* x = root->left; // node 20
    Node* succ = inorderSuccessor(root, x);
    Node* pre = inorderPredecessor(root, x);

    if(succ) cout << "Successor of 20: " << succ->data << "\n";
    if(pre) cout << "Predecessor of 20: " << pre->data << "\n";

    return 0;
}
