#include <iostream>
using namespace std;

struct BST{
	int data;
	BST* parent;
	BST* left;
	BST* right;
};
BST* newnode(BST* parent,int val){
	BST* node = new BST;
	node->left = node->right = NULL;
	node->data = val;
	return node;
}
BST* insert(BST* root,int val){
	if (root == NULL){
		return newnode(root,val);
	}
	else if (val > root->data){
		BST* rchild = insert(root->right,val);
		root->right = rchild;
		rchild->parent = root;
	}
	else{
		BST* lchild = insert(root->left,val);
		root->left = lchild;
		lchild->parent = root;
	}
	return root;
}
int maxval(BST* root){
	if (root->right == NULL) return root->data;
	else{
		maxval(root->right);
	}
}
int minval(BST* root){
	if (root->left == NULL) return root->data;
	else{
		minval(root->left);
	}
}
int pred(BST* root,int val){
	while (root->data != val){
		if (root->data < val) root = root->right;
		else root = root->left;
	}
	if (root->left == NULL){
		BST* y = root->parent;
		while (root != NULL && root == y->left){
			root = y;
			y = y->parent;
		}
		return y->data;
	}
	else{
		return minval(root);
	}
}
int succ(BST* root,int val){
	while (root->data != val){
		if (root->data < val) root = root->right;
		else root = root->left;
	}
	if (root->right == NULL){
		BST* y = root->parent;
		while (root != NULL && root == y->right){
			root = y;
			y = y->parent;
		}
		return y->data;
	}
	else{
		return maxval(root);
	}
}
bool find(BST* root,int val){
	while (true){
		if (root == NULL) return false;
		if (val == root->data) return true;
		if (val > root->data){
			root = root->right;
		}
		else if (val < root->data){
			root = root->left;
		}
	}
}
void InOrder(BST* root){
	if(root != NULL){
		InOrder(root->left);
		cout<<root->data<<"\t";
		InOrder(root->right);
	}
}
void del(BST* root,int val){
	while (root != NULL && root->data != val){
		if (root->data > val) root = root->left;
		else if (root->data < val) root = root->right;
	}
	//Not found
	if (root == NULL) return;

	else{
	//incase of no children
		if (root->left == NULL && root->right == NULL){
			if (root->parent->left == root){
				root->parent->left = NULL;
			}
			else{
				root->parent->right = NULL;
			}
			delete root;
		}
	//incase of one child
		if (root->left != NULL && root->right == NULL){
			root->left->parent = root->parent;
			if(root->parent->left == root){
				root->parent->left = root->left;
			}
			else{
				root->parent->right = root->left;
			}
		}
		if (root->right != NULL && root->left == NULL){
			root->right->parent = root->parent;
			if(root->parent->left == root){
				root->parent->left = root->right;
			}
			else{
				root->parent->right = root->right;
			}
		}
	//incase of 2 children
		root->data = pred(root,root->data);
		del(root->left,root->data);
	}
}
int main(){
	BST* root = NULL;
	root = insert(root,12);
	root = insert(root,10);
	root = insert(root,11);
	root = insert(root,13);
	root = insert(root,6);
	root = insert(root,2);
	root = insert(root,1);
	InOrder(root);
	del(root,1);
	cout<<"\n";
	InOrder(root);
	cout<<"\n";
}