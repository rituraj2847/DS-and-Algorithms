#include <iostream>
using namespace std;
#define MAX 8
class Deque{
	private:
		int arr[MAX];
		int front,rear;
	public:
		Deque(){
			front=rear=-1;
		}
		void addtobeg(int);
		void addtoend(int);
		void delfromend();
		void delfrombeg();
		void print();
		bool isempty(){
			return (front==-1);
		}
		bool isfull(){
			return (front==(rear+1)%(MAX-1));
		}
};
void Deque::addtobeg(int val){
	if (isfull()){
		cout<<"Deque overflow\n";
		return;
	}
	if (isempty()){
		front=rear=0;
	}
	else if (front==0){
		front = MAX-1;
	}
	else{
		front--;
	}
	arr[front] = val;
}
void Deque::addtoend(int val){
	if (isfull()){
		cout<<"Deque overflow\n";
		return;
	}
	if (isempty()){
		front=rear=0;
	}
	else if (rear==MAX-1){
		rear=0;
	}
	else{
		rear++;
	}
	arr[rear] = val;
}
void Deque::delfromend(){
	if (isempty()){
		cout<<"Deque underflow\n";
		return;
	}
	else if (rear==0){
		rear = MAX-1;
	}
	else{
		rear--;
	}
}
void Deque::delfrombeg(){
	if (isempty()){
		cout<<"Deque underflow\n";
		return;
	}
	else if (front == MAX-1){
		front=0;
	}
	else{
		front++;
	}
}
void Deque::print(){
	cout<<"\n";
	if(front > rear){
		for(int i=front;i<MAX;i++)
			cout<<arr[i]<<" ";
		for(int i=0;i<=rear;i++)
			cout<<arr[i]<<" ";
	}
	else{
		for(int i=front;i<=rear;i++)
			cout<<arr[i]<<" ";
	}
}
int main(){
	Deque d;
	d.addtobeg(12);
	d.print();
	d.addtoend(14);
	d.print();
	d.addtobeg(9);
	d.print();
	d.addtoend(16);
	d.print();
	d.addtobeg(20);
	d.addtobeg(27);
	d.addtobeg(42);
	d.addtobeg(29);
	d.print();
	d.delfromend();
	d.print();
}
