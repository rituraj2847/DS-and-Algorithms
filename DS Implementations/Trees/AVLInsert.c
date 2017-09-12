#include <stdio.h>
#include <stdlib.h>

struct Node{
	int key;
	struct Node* left;
	struct Node* right;
	int height;
};
struct Node* newNode(int key){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}
int height(struct Node* node){
	if (node == NULL) return 0;
	return node->height;
	}
	
int getBalance(struct Node* node){
	if (node == NULL)
        return 0;
	return height(node->left) - height(node->right);
	}
int max(int a, int b){
	return a > b?a : b ;
	}
struct Node* rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node* leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}

struct Node* avlInsert(struct Node* node, int key){
	if (node == NULL) return newNode(key);
	if (key > node->key){
		node->right = avlInsert(node->right, key);
		}
	else if (key < node->key){
		node->left = avlInsert(node->left, key);
		}
	else return node; // BST doesn't allow same values
	node->height = 1 + max(height(node->left), height(node->right));
	int bal = getBalance(node);
	if (bal > 1 && key < node->left->key){
		return rightRotate(node);
		}
	if (bal > 1 && key > node->left->key){
		node->left = rightRotate(node->left);
		return leftRotate(node);
		}
	if (bal < -1 && key > node->right->key){
		return leftRotate(node);
		}
	if (bal < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
		}
	return node;
	}
void preOrder(struct Node* root){
	if (root != NULL){
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
		}
	}
int main()
{
	struct Node* root = NULL;
	root = avlInsert(root, 10);
	root = avlInsert(root, 20);
	root = avlInsert(root, 30);
	root = avlInsert(root, 40);
	root = avlInsert(root, 50);
	root = avlInsert(root, 25);	
	preOrder(root);
	return 0;
	}

