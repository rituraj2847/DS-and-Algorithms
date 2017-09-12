//Merge Sort
#include <iostream>
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
	int n;
	cout<<"enter the size : ";
	cin>>n;
	int arr[n];
	cout<<"enter the elements : ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
		}
	}
