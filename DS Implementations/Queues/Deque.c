#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6
void addtobeg(int arr[],int* front,int* rear,int num){
	if(*front == -1){
		(*front)++;
		(*rear)++;
		arr[*front] = num;
	}
	else if(*front == 0 && *rear == MAXSIZE-1){
			printf("Overflow\n");
		}
	else if(*front > 0){
		(*front)--;
		arr[*front] = num;
		}
	else{
		for(int i=*rear;i>=*front;i--){
			arr[i+1] = arr[i];
			}
		arr[*front] = num;
		(*rear)++;
	}
}
void addtoend(int arr[],int *front,int *rear,int num){
	if(*front == -1){
		(*front)++;
		(*rear)++;
		arr[*front] = num;
	}
	if(*front == 0 && *rear == MAXSIZE){
		printf("Overflow");
	}
	else if(*rear != MAXSIZE-1){
		(*rear)++;
		arr[*rear] = num;
		}
	else{
		for(int i=*front;i<=*rear;i++){
			arr[i-1] = arr[i];
		}
		arr[*rear] = num;
		(*front)--;
	}
}
void delfromend(int arr[],int *front,int *rear){
	if(*front == -1){
		printf("No elements to delete\n");
		}
	else if(*front == *rear){
		*front = *rear = -1;
		}
	else{
		(*rear)--;
		}
	printf("Rear: %d",*rear);
}
void delfrombeg(int arr[],int *front,int *rear){
	if(*front == -1){
		printf("No elements to delete\n");
		}
	else if(*front == *rear){
		*front = *rear = -1;
		}
	else{
		(*front)++;
	}
}
void display(int arr[],int front,int rear){
	printf("\n");
	if(front <= rear){
		for(int i=front;i<=rear;i++)
				printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
	int front,rear,arr[MAXSIZE];
	int num,choice;
	front=rear=-1;
	while(choice!=5){
		display(arr,front,rear);
		printf("1. Add to beginning\n");
		printf("2. Add to end\n");
		printf("3. Delete from beginning\n");
		printf("4. Delete from end\n");
		printf("5. Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter the no.: ");
					scanf("%d",&num);
					addtobeg(arr,&front,&rear,num);
					break;
			case 2: printf("Enter the no.: ");
					scanf("%d",&num);
					addtoend(arr,&front,&rear,num);
					break;
			case 3: delfrombeg(arr,&front,&rear);
					break;			
			case 4: delfromend(arr,&front,&rear);	
					break;
			case 5: exit(0);
		}
	}
	}
