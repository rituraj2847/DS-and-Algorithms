#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[100000];
	srand(time(NULL));
	for(int i=0;i<100000;i++){
		arr[i] = i;
	}
	int len = sizeof(arr)/sizeof(arr[0]);
	clock_t beg_time = clock();
	for(int i=0;i<len;i++){

		while(i>0 && arr[i] < arr[i-1]){
			swap(arr[i],arr[i-1]);
			i--;
		}
	}
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"Time: "<<(float)(clock()-beg_time)/CLOCKS_PER_SEC<<" seconds\n";
}