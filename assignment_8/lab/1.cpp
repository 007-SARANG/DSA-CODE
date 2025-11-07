#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(nullptr),right(nullptr) {}
	};
	Node* UserInput(){
		int val;
		cout<<"Enter node value: "<<val<<endl;
		cin>>val;													
		if(val==-1) return nullptr;
		Node* newNode = new Node(val);
		cout<<"Enter left child of "<<val<<endl;
		newNode->left=UserInput();
		cout<<"Enter right child of "<<val<<endl;
		newNode->right=UserInput();
		return newNode;													
	}
	void preorder(Node* root){
		if(root == nullptr) return;
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);				
	}
	void inorder(Node* root){
		if(root == nullptr) return;
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);								
	}                       
	 void postorder(Node* root){ 
		if(root == nullptr) return; 
		postorder(root->left);
		postorder(root->right);									
		cout<<root->data<<" ";								
	}                         
int main()                   
{	
		cout<<"Create a tree"<<endl;
		Node* root = UserInput();					
  cout<<"Pre-Order: ";
		preorder(root);          
 	cout<<endl;              
 	cout<<"In-Order: ";       
 	inorder(root);                
 	cout<<endl;                    
 	cout<<"Post-order: ";
 	postorder(root);
 	cout<<endl;
 	                   
 	return 0;     
}            
                  		 	
             		 		
													
  																																																							          															     																																							 
