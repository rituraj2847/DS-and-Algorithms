#include <stdio.h>
#include <stdlib.h>
//Program for inserting a node at the beginning

void Insert(int);
void Print();
struct Node {
	int data;
	struct Node* link;		//Node* link in C++
};
struct Node* head;
void Insert(int x){
	struct Node* temp=malloc(sizeof(struct Node));    //new node() in C++
	temp->data=x;
	temp->link=head;
	head=temp;
	}
void Print(){
	struct Node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->link;
	}
}
	

int main()
{
	head=NULL;
	printf("How many numbers?");
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("ENter the number:\n");
		printf("%d", sizeof(int));
		scanf("%d",& x);
		Insert(x);
		Print();
}
}
