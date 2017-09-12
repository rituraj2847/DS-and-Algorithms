#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* GetNewNode(int data){
	struct Node* root=(struct Node*)malloc(sizeof(struct Node));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
	}
struct Node* Insert(struct Node* root, int data){
	if(root==NULL){
		root=GetNewNode(data);
	}
	else if(data<=root->data){
		root->left=Insert(root->left,data);
		}
	else {
		root->right=Insert(root->right, data);
	}
		return root;
		}
int FinMin(struct Node* root){
	if(root==NULL) return 0;
	else {
		while(root->left!=NULL){
			root=root->left;}
		return root->data;
		}
	}
int FinMax(struct Node* root){
	if(root==NULL) return 0;
	else {
		while(root->right!=NULL){
			root=root->right;}
		return root->data;
	}
}
int main()
{	struct Node* root=NULL;
	root=Insert(root,12);
	root=Insert(root,2);
	root=Insert(root,6);
	root=Insert(root,13);
	root=Insert(root,20);
		printf("The min No is : %i",FinMin(root));
	
		printf("\nThe max No is : %i",FinMax(root));
	return 0;
}
