#include <stdio.h>
#include <stdlib.h>
//Program for deleting a node at nth position
int i;
struct Node{
	int data;
	struct Node* next;
};
struct Node* head;
void Insert(int val){
	struct Node* temp=malloc(sizeof(struct Node));
	temp->data=val;
	temp->next=NULL;
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
void Print(){
	struct Node* temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data); //or *temp.data
		temp=temp->next;
}
}
void Delete(int n){
	struct Node* temp=head;
	if(n==1){
		head=temp->next;
		free(temp);
		return;
	}
	for(i=0;i<n-2;i++){
		temp=temp->next;
	}
	struct Node* temp2=temp->next;
	temp->next=temp2->next;
	free(temp2);
}
int main(){
	int n;
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
	printf("\nIndex of the Element to be deleted:");
	scanf("%d",&n);
	Delete(n);
	Print();
	return 0;
}
