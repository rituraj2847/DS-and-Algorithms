#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[]={4,5,6,7};
	srand(time(NULL));
	//for(int i=0;i<10000;i++){
	//	arr[i] = rand()%10000;
	//}
	int len = sizeof(arr)/sizeof(arr[0]);
	clock_t beg_time = clock();
	for(int i=0;i<len;i++){

		for(int j=0;j<len-i-1;j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	for(int i=0;i<len;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"Time: "<<(clock()-beg_time)/CLOCKS_PER_SEC<<"\n";

}