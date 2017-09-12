#include <iostream>
using namespace std;
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
	}
void quickSort(int arr[],int l,int r){
	if (l-r>=0) return;
	int yellow = l+1;
	for(int green = l+1; green<=r; green++){
		if(arr[green] < arr[l]){
			swap(&arr[green], &arr[yellow]);
			yellow++;
		}
	}
	swap(&arr[l], &arr[yellow-1]);

	quickSort(arr, l, yellow-2);
	quickSort(arr, yellow, r);
	}
int main(){
	int arr[]={65,43,21,89,76,91,55};
	int len = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, len-1);
	for(int i=0;i<7;i++)
	cout<<arr[i]<<" ";
	}
