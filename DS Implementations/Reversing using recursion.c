#include <stdio.h>
#include <stdlib.h>
//Program for displaying the linkedlist using Recursion
int i;
struct Node{
	int data;
	struct Node* next;
	};
void Print(struct Node* p){
	struct Node* temp=p;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;			
		}
}
struct Node* Insert(struct Node* p,int val){
	struct Node* temp=malloc(sizeof(struct Node));
	temp->data=val;
	temp->next=NULL;
	if(p==NULL){
		p=temp;
		return p;
	}
	struct Node* temp2=p;
	while(temp2->next!=NULL){
		temp2=temp2->next;
	}
	temp2->next=temp;
	return p;
}
void Reverse(struct Node* p){
	if(p==NULL){
		return;
		}
	Reverse(p->next);
	printf("%d ",p->data);
}
int main(){
	struct Node* head=NULL;

	head=Insert(head,3);
	head=Insert(head,5);
	head=Insert(head,2);
	head=Insert(head,8);
	
	Print(head);
	
	printf("\nThe reverse list is :\n");
	Reverse(head);
	return 0;
	}

	
