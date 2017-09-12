#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* insert(Node* root,int val){
	Node* node = new Node;
	node->data = val;
	node->next = NULL;
	if(root == NULL){
		root = node;
	}
	else{
	Node* temp = root;
	while(temp->next != NULL){
		temp = temp->next;
		}
	temp->next = node;
	}
	return root;
}
void display(Node* root){
	Node* temp = root;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
Node* concat(Node* root1, Node* root2){
	Node* temp1 = root1;
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}
	temp1->next = root2;
	return root1;
}
int main(){
	Node* root1 = NULL;
	Node* root2 = NULL;
	Node* root = NULL;
	root1 = insert(root1,2);
	root1 = insert(root1,5);
	root1 = insert(root1,6);
	root1 = insert(root1,7);
	root2 = insert(root2,0);
	root2 = insert(root2,1);
	root2 = insert(root2,4);
	root2 = insert(root2,8);
	root = concat(root1,root2);
	display(root);
}