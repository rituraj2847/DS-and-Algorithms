#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* newNode(int data){
	Node* node = new Node;
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return node;
}
void preOrderIterative(Node* root){
	stack<Node*> s;
	while(true){
		while(root){
			cout<<root->data<<" ";
			if(root->right) s.push(root);
			root = root->left;
			}
		if(!s.empty()){
			root = s.top();
			s.pop();
			root = root->right;
		}
		else break;
	}

}
void postOrderIterative(Node* root){
	stack<Node*> s;
	do{
		while(root){
			if(root->right) s.push(root->right);
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		if(!s.empty() && s.top() == root->right){
			s.pop();
			s.push(root);
			root = root->right;
		}
		else{
			cout<<root->data<<" ";
			root = NULL;
		}
	}while(!s.empty());
}
void inOrderIterative(Node* root){
	stack<Node*> s;
	while(true){
		while(root){
			s.push(root);
			root = root->left;
			}
		if(!s.empty()){
			root = s.top();
			s.pop();
			cout<<root->data<<" ";
			root = root->right;
			}
		else break;
		}
	}
int main()
{
    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("Post order traversal of binary tree is :\n");
    printf("[");
    postOrderIterative(root);
    printf("]");
    printf("\nPre order traversal of binary tree is :\n");
    printf("[");
    preOrderIterative(root);
    printf("]");
    printf("\nIn order traversal of binary tree is :\n");
    printf("[");
    inOrderIterative(root);
    printf("]");
     
 
    return 0;
}
