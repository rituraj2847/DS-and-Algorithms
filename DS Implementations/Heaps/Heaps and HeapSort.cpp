#include <iostream>
using namespace std;

void swap(int arr[],int i,int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void maxHeapify(int arr[],int heap_size,int i){
	int left = 2*i+1;
	int right = 2*i+2;
	int largest = i;
	if(left <= heap_size && arr[left] > arr[largest]){
		largest = left;
	}
	if(right <= heap_size && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != i){
		swap(arr,largest,i);
		maxHeapify(arr,heap_size,largest);
	}
}
void buildMaxHeap(int arr[],int length){
	for(int i=length/2;i>=0;i--){
		maxHeapify(arr,length,i);
	}
}
void heapSort(int arr[],int heap_size){
	buildMaxHeap(arr,heap_size);
	for(int i=heap_size;i>0;i--){
		swap(arr,i,0);
		heap_size -= 1;
		maxHeapify(arr,heap_size,0);
	}
}
int main(){
	int arr[]={7,3,8,4,1,9,2,5};
	int heap_size = sizeof(arr)/sizeof(arr[0])-1;
	heapSort(arr,heap_size);
	for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
		cout<<arr[i]<<" ";
	}
}