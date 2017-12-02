#include <bits/stdc++.h>
using namespace std;
void quickSort(int arr[],int l,int r){
	if (l-r>=0) return;
	int yellow = l+1;
	for(int green = l+1; green<=r; green++){
		if(arr[green] < arr[l]){
			swap(arr[green], arr[yellow]);
			yellow++;
		}
	}
	swap(arr[l], arr[yellow-1]);

	quickSort(arr, l, yellow-2);
	quickSort(arr, yellow, r);
	}
int main(){
	int arr[100000];
	clock_t beg_time = clock();
	srand(time(NULL));
	for(int i=0;i<100000;i++){
		arr[i] = rand()%100000;
	}
	int len = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, len-1);

	for(int i=0;i<len;i++)
	cout<<arr[i]<<" ";
 	cout<<"Time: "<<(float)(clock()-beg_time)/CLOCKS_PER_SEC<<" seconds\n";

	}

