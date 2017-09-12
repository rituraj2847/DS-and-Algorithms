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
void merge(Node* root1, Node* root2){
	int val;
	Node* temp1 = root1;
	Node* temp2 = root2;
	Node* newlist = NULL;
	while(temp1 != NULL && temp2 != NULL){
		if (temp1->data > temp2->data){
			val = temp2->data;
			temp2 = temp2->next;
		}
		else{
			val = temp1->data;
			temp1 = temp1->next;
		}
		newlist = insert(newlist,val);
	}
	while(temp1 != NULL){
		newlist = insert(newlist,temp1->data);
		temp1 = temp1->next;
	}
	while(temp2 != NULL){
		newlist = insert(newlist,temp2->data);
		temp2 = temp2->next;
	}
	display(newlist);
}
int main(){
	Node* root1 = NULL;
	Node* root2 = NULL;
	root1 = insert(root1,2);
	root1 = insert(root1,5);
	root1 = insert(root1,6);
	root1 = insert(root1,7);
	root2 = insert(root2,0);
	root2 = insert(root2,1);
	root2 = insert(root2,4);
	root2 = insert(root2,8);
	merge(root1,root2);
}