#include <iostream>
using namespace std;
int size[8];
void makeSet(int arr[]){
	for (int i=0;i<8;i++){
		arr[i] = i;
		size[i] = 1;
	}
}
//modified root for path compression
int root(int A[],int x){
	if (x == A[x])
		return x;
	A[x] = root(A,A[x]);
	return A[x];
}
void unionFind(int A[],int a,int b){
	int root_a = root(A,a);
	int root_b = root(A,b);
	if (size[root_b] > size[root_a]){
		A[root_a] = root_b;
		size[root_b] += size[root_a];
	}
	else{
		A[root_b] = root_a;
		size[root_a] += size[root_b];
	}
}
int main(){
	int A[8];
	makeSet(A);
	unionFind(A,1,2);
	unionFind(A,2,3);
	unionFind(A,4,5);
	unionFind(A,6,7);
	unionFind(A,5,6);
	unionFind(A,3,7);
	//Printing roots
	for(int i=0;i<8;i++){
		cout<<i<<": "<<A[i]<<"\n";
	}
}