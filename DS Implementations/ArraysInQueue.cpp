#include <stdio.h>
#define max 120

class Queue{
	private:
	int queue[max];
	int front;
	int rear;
	public:
	Queue()
	{
		front = -1; 
		rear = -1;
	}

	bool IsEmpty(){
		return (front==-1 && rear==-1);
		}
	bool IsFull(){
		return((rear+1)%max==front ? true:false);
		}
	void Enqueue(int x){
		if(IsFull()){
			return ;
			}
		else if(IsEmpty()){
			front+=1;
			rear+=1;
		}
		else {
			rear=(rear+1)%max;
			}
		queue[rear]=x;
	}
	void Dequeue(){
		if(IsEmpty()){
			return;
			}
		else if (front==rear){
			front=rear=-1;
			}
			else front=(front+1)%max;
		}
void Print(){
	printf("Queue: ");
	for(int i=0;i<(rear+max-front)%max + 1;i++){
		int index=(front+i)%max;
		printf("%d ",queue[index]);
		}
		printf("\n");
	}
};
	Queue S;
int main(){
	S.Enqueue(2);S.Print();
	S.Enqueue(4);S.Print();
	S.Enqueue(1);S.Print();
	S.Enqueue(7); S.Print();
	S.Dequeue(); S.Print();
	return 0;
}
	
