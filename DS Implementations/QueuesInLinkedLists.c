#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* next;
	};
	struct Node* front;
	struct Node* rear;
void Enqueue(int x){
	struct Node* temp=malloc(sizeof(struct Node));
	temp->data=x;
	temp->next=NULL;
	if(front==NULL){
	front=temp;
	rear=temp;
	return;
}
	rear->next=temp;
	rear=temp;
}
void Dequeue(){
	struct Node* temp=front;
	if(front==NULL){
		return;
	}	
	if(front==rear){
		front=rear=NULL;
		}
	else
	front=temp->next;
	free(temp);
	}
	void Print(){
		struct Node* temp=front;
		printf("Queue : ");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
			}
			printf("\n");
		}
int main(){
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();
	return 0;
}
