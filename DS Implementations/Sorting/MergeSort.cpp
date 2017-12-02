//Merge Sort
#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int mid, int r){
	int tmp[r-l+1], posl=l, posr=mid+1;
	int i=0;
	while(posl <= mid && posr <= r ){
		if(arr[posl] > arr[posr]){
			tmp[i++] = arr[posr];
			posr++;
			}
		else{
			tmp[i++] = arr[posl];
			posl++;
			}
		}
	while(posl <= mid){
		tmp[i++] = arr[posl];
		posl++;
		}
	while(posr <= r){
		tmp[i++] = arr[posr];
		posr++;
		}
	i=0;
	for(int j=l; j<=r; j++){
		arr[j] = tmp[i++];
	}
}
void mergeSort(int *arr, int l, int r){
	int mid = (l+r)/2;
	if(l<r){
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}
int main(){
	int arr[100000];
	clock_t beg_time = clock();
	srand(time(NULL));
	for(int i=0;i<100000;i++){
		arr[i] = i;
	}
	int len = sizeof(arr)/sizeof(arr[0]);

	cout<<"Time: "<<(float)(clock()-beg_time)/CLOCKS_PER_SEC<<" seconds\n";

	mergeSort(arr,0,len-1);
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
		}
	}
