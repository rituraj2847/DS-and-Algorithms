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
int max(int l, int r){
	return l>r?l:r;
	}
int height(struct Node* root){
	if(root==NULL) return -1;
	else {
		int left_tree=height(root->left);
		int right_tree=height(root->right);
		return max(left_tree,right_tree) +1;
	}
	}
int main()
{	struct Node* root=NULL;
	root=Insert(root,12);
	root=Insert(root,2);
	root=Insert(root,6);
	root=Insert(root,13);
	root=Insert(root,22);
	root=Insert(root,20);
	printf("The Height of Tree is : %i",height(root));
	return 0;
}
