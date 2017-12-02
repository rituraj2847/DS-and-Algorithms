#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6
struct queue{
	int arr[MAXSIZE];
	int front,rear;
};
void display(struct queue q){
	if(q.front == -1){
	return;
	}
	if(q.front <= q.rear){
	for(int i=q.front;i<=q.rear;i++){
		printf("%6d  ",q.arr[i]);
	}
    }
	else if(q.front > q.rear){
		for(int i=q.front;i<MAXSIZE;i++){
		printf("%6d  ",q.arr[i]);
		}
		for(int i=0;i<=q.rear;i++){
		printf("%6d  ",q.arr[i]);
		}
		}
	printf("\n");
}
int main(){
	struct queue q;
	q.front = q.rear = -1;
	int num,choice;
	while(choice!=4){
		display(q);
		printf("1. Insert\n");
		printf("2. Pop\n");
		printf("3. Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter the no.: ");
					scanf("%d",&num);
					if (q.front == (q.rear+1)%MAXSIZE){
						printf("Overflow !\n");
					}
					else if (q.front == -1){
						(q.rear)++;
						q.front++;
						q.arr[q.front] = num;
					}
					else{
						q.rear = (q.rear+1)%MAXSIZE;
						q.arr[q.rear] = num;
					}
					break;
			case 2: if (q.front == -1){
						printf("Underflow !\n");
					}
					else{
						printf("The popped element is: %d\n",q.arr[q.front++]);
					}
					break;
			case 3: exit(0);
		}
	}
}
