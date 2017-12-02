#include <iostream>
using namespace std;

void counting_sort(int A[],int n){
	int k=0;
	for(int i=0;i<n;i++){
		k = max(k,A[i]);
	}
	int Aux[k+1];
	for(int i=0;i<k+1;i++){
		Aux[i] = 0;
	}
	for(int i=0;i<k;i++){
		Aux[A[i]]++;
	}
	for(int i=0;i<k+1;i++){
		int temp=Aux[i];
		while(temp>0){
			cout<<i<<" ";
			temp--;
		}
	}
	
}
int main(){
	int A[] = {6,5,8,3,4,1,1,0};
	int size = sizeof(A)/sizeof(A[0]);
	counting_sort(A,size);
}