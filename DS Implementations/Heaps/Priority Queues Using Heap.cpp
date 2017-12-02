#include <iostream>
using namespace std;

class MaxHeap{
		int *arr;
		int capacity;
		int heap_size;
		
	public:
		MaxHeap(int);
		int left_child(int i){ return (2*i+1); }
		int right_child(int i){ return (2*i+2); }
		void maxHeapify(int);
		int parent(int i){ return (i-1)/2; }
		int getMax(){ return arr[0]; }
		int extractMax();
		void insertKey(int);
		void increaseKey(int,int);
};
MaxHeap::MaxHeap(int cap){
	heap_size = 0;
	capacity = cap;
	arr = new int[cap];
}
void MaxHeap::maxHeapify(int i){
	int left = left_child(i);
	int right = right_child(i);
	int largest = i;
	if(left <= heap_size && arr[left] > arr[largest]){
		largest = left;
	}
	if(right <= heap_size && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != i){
		swap(arr[largest],arr[i]);
		maxHeapify(largest);
	}
}
void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void MaxHeap::increaseKey(int i,int key){
	if (key < arr[i]){
		cout<<"Key is smaller than current value\n";
	}
	arr[i] += key;
	while(i>0 && arr[parent(i)] < arr[i]){
		swap(arr[parent(i)],arr[i]);
		i = parent(i);
	}
}
void MaxHeap::insertKey(int key){
	if(heap_size+1 > capacity){
		cout<<"Overflow\n";
	}
	else{
		heap_size++;
		int i = heap_size-1;
		arr[i] = 0;
		increaseKey(i,key);
	}
}
int MaxHeap::extractMax(){
	swap(arr[0],arr[heap_size]);
	heap_size -= 1;
	maxHeapify(0);
	return arr[heap_size+1];
}

int main(){
	MaxHeap h(11);
	h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMax() << " ";
    cout << h.getMax() << " ";
     return 0;
}