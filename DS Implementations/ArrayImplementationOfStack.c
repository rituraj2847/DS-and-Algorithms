#include <stdio.h>
#define MAX_SIZE 101

int arr[MAX_SIZE];
int top=-1;
void Push(int x){
	if(top==MAX_SIZE-1){
		printf("Overflow !");
		return;
		}
	arr[++top]=x;
	}
void Pop(){
	if(top==-1){return;}
	top--;
	}
int Top(){
	return top;
	}
void IsEmpty(){
	if(top==-1)printf("Empty Stack");
	else printf("Not empty");
	}
void Print(){
	for(int i=0;i<=top;i++){
		printf("%d ",arr[i]);
		}
		printf("\n");
		}
int main(){
	Push(2);Print();
	Push(7);Print();
	Push(5);Print();
	Pop();Print();
	printf("Top: %d\n",Top());
	IsEmpty();
	}
