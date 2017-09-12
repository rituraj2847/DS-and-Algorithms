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
int Search(struct Node* root,int data){
	if(root==NULL) return 0;
	if(root->data==data) return 1;
	else if(data<=root->data) return Search(root->left,data);
	else return Search(root->right,data);
}
int main()
{	int number;
	struct Node* root=NULL;
	root=Insert(root,12);
	root=Insert(root,2);
	root=Insert(root,6);
	root=Insert(root,13);
	root=Insert(root,20);
	printf("Enter the number to be searched :");
	scanf("%i",&number);
	if (Search(root,number)==1)
	printf("Found\n");
	else printf("Notfound");
	return 0;
}

