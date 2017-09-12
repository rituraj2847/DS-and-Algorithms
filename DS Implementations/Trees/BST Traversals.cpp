#include<iostream>
#include<stdlib.h>

using namespace std;

struct BSTNode{
	int data;
	BSTNode* left;
	BSTNode* right;
	};
BSTNode* GetNewNode(int data){
	BSTNode* root = (BSTNode*)malloc(sizeof(BSTNode));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
	}
BSTNode* Insert(int data, BSTNode* root){
	if(root == NULL){
		root = GetNewNode(data);
		}
	else if(root->data >= data){
		root->left = Insert(data, root->left);
		}
	else {root->right = Insert(data, root->right);}
	return root;
	}
void PreOrder(BSTNode* root){
	if(root != NULL){
		cout<<root->data<<"\t";
		PreOrder(root->left);
		PreOrder(root->right);
		}
	}
void InOrder(BSTNode* root){
	if(root != NULL){
		InOrder(root->left);
		cout<<root->data<<"\t";
		InOrder(root->right);
	}
}
void PostOrder(BSTNode* root){
	if(root != NULL){
		PostOrder(root->right);
		cout<<root->data<<"\t";
		PostOrder(root->left);
	}
	}
int main(){
	BSTNode* root = NULL;
    root = Insert(10, root);
	root = Insert(6, root);
	root = Insert(9, root);
	root = Insert(3, root);
	root = Insert(2, root);
	root = Insert(7, root);
	root = Insert(4, root);
	cout<<"PreOrder Traversal: ";
	PreOrder(root);
	cout<<"\nInOrder Traversal: ";
	InOrder(root);
	cout<<"\nPostOrder Traversal: ";
	PostOrder(root);
	}
