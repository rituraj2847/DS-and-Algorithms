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
	else if(root->data > data){
		root->left = Insert(data, root->left);
		}
	else root->right = Insert(data, root->right);
	return root;
} 
BSTNode* FindMin(BSTNode* root){
	while (root->left != NULL){
		root = root->left;
		}
		return root;
}
BSTNode* Delete(int data, BSTNode* root){
	if(root == NULL){
		return NULL;
		}
	else if(root->data > data){
		root->left = Delete(data, root->left);
		return root;
	}
	else if(root->data < data){
		root->right = Delete(data, root->right);
		return root;
		}
	else{
		// No child
		if(root->left == NULL && root->right == NULL){
			free(root);
			return NULL;
			}
		// 1 child
		else if(root->left == NULL){
			struct BSTNode* temp = root->right;
			free(root);
			return temp;
			}
		else if(root->right == NULL){
			struct BSTNode* temp = root->left;
			free(root);
			return temp;
		}
		// 2 children
			struct BSTNode* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(temp->data, root->right);
			return root;
		}
	}
void InOrder(BSTNode* root){
	if(root != NULL){
		InOrder(root->left);
		cout<<root->data<<"\t";
		InOrder(root->right);
	}
}
int main(){
	BSTNode* root = NULL;
    root = Insert(10, root);
	root = Insert(16, root);
	root = Insert(13, root);
	root = Insert(3, root);
	root = Insert(2, root);
	root = Insert(7, root);
	root = Insert(4, root);
	cout<<"\nInOrder Traversal before delete: ";
	InOrder(root);
	root = Delete(3, root);
	cout<<"\nInOrder Traversal after delete: ";
	InOrder(root);
	cout<<"\n";
}
