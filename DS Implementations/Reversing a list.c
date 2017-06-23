#include <stdio.h>
#include <stdlib.h>
//Program for reversing the linkedlist
int i;
struct Node{
	int data;
	struct Node* next;
	};
struct Node* head;
void Print(){
	struct Node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
}
}
void Insert(int val){
	struct Node* temp=malloc(sizeof(struct Node));
	temp->data=val;
	if(head==NULL){
		head=temp;
	}
else{
	struct Node* temp2=head;
	while(temp2->next!=NULL){
		temp2=temp2->next;
	}
	temp2->next=temp;
}
}
void Reverse(){
	struct Node *current,*prev,*temp;
	prev=NULL;
	current=head;
	while(current!=NULL){
		temp=current->next;
		current->next=prev;
		prev=current;
		current=temp;
	}
	head=prev;
}

int main(){
	head=NULL;
	/*printf("How many values?");
	scanf("%d",&i);
	for(j=0;j<i;j++){
		printf("Value %d: ",j+1);
		scanf("%d",&val);
		Insert(val);
	}*/
	Insert(3);
	Insert(5);
	Insert(2);
	Insert(8);
	
	Print();
	printf("\nReversed list is:");
	Reverse();
	Print();
	return 0;
	}
