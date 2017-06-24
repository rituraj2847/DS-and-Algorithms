#include <stdio.h>
#include <stdlib.h>
//Program for inserting a node at nth position
int i;
struct Node{
	int data;
	struct Node* next;
};
struct Node* head;
void Insert(int val, int n){
	struct Node* temp=malloc(sizeof(struct Node));
	temp->data=val;
	temp->next=NULL;
	if(n==1){
	temp->next=head;
	head=temp;
	return ;
	}
	struct Node* temp2=head;
	for(i=0;i<n-2;i++){
		temp2=temp2->next;
	}
	temp->next=temp2->next;
	temp2->next=temp;
}
void Print(){
		struct Node* temp=head;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
	}		
}
int main(){
	head=NULL;
	int data,n,num;
	printf("Enter no of values you want to insert\n");
	scanf("%d",&num);
	for(i=0;i<num;i++){
	printf("\nEnter the value and index: ");
	scanf("%d %d",&data,&n);
	Insert(data,n);
	Print();
}
return 0;
}

