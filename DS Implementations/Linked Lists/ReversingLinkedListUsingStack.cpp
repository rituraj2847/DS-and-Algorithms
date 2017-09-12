#include <stdio.h>
#include <stack>
#include <stdlib.h>
using namespace std;
struct Node{
	int data;
	Node* next;
	};
stack<struct Node*> s;
Node* head=NULL;
void Insert(int val){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=val;
	temp->next=NULL;
	if (head==NULL){
		head=temp;
		}
	Node* temp2=head;
	while(temp2->next!=NULL){
		temp2=temp2->next;
		}
	temp2=temp;
	}
void Reverse(){
	Node* temp2=s.top();
	head=temp2;
	s.pop();
	while(!s.empty()){
		temp2->next=s.top();
		s.pop();
		temp2=temp2->next;	
	}
}
void Print(){
	Node* temp=head;
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->next;
		}
	}
int main()
{
	Node* temp=head;
	Insert(4);
	Insert(1);
	Insert(6);
	Insert(3); 
	Print();
	while(temp!=NULL){
		s.push(temp);
		temp=temp->next;
		}
	Reverse();
	Print();
	return 0;

}

