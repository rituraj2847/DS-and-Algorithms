#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
	};
struct Node* top=NULL;
void Push(int x){
	struct Node* temp=malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=top;
	top=temp;
	}
void Pop(){
	struct Node* temp;
	if(top==NULL){return;}
	temp=top;
	top=temp->next;
	}
void Print(){
	struct Node* temp=top;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
		}
		printf("\n");
}
void Top(){
	struct Node* temp=top;
	int i=-1;
	while(temp!=NULL){
		temp=temp->next;
	i++;
}
	printf("\nTop:%2d\n",i);
}
void IsEmpty(){
	if(top==NULL)
	printf("Empty Stack");
	else printf("Non-Empty Stack");
	}
	
int main(){
	Push(2);Print();
	Push(7);Print();
	Push(5);Print();
	Pop();Print();
	Top();
	IsEmpty();
	}
