#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	};
struct Node* head;
void Push(int val){
	struct Node* temp=malloc(sizeof(struct Node));
	temp->data=val;
	temp->next=head;
	head=temp;
}
void Pop(){
	struct Node* temp=head;
	struct Node* temp2=temp->next;
	head=temp2;
	}
void Print(){
	struct Node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
		}
		printf("\n");
		}
int main(){
	Push(2);
	Push(5);
	Push(1);
	Push(8);
	Print();
	Pop();
	Print();
}
	
	

