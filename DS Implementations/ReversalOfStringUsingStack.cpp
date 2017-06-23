#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#include <stack> //stack for standard template library

void Reverse(char *C, int n){
	stack<char> S;
	//loop for push
	for(int i=0;i<n;i++){
		S.push(C[i]);
		}
	//loop for pop
	for(int i=0;i<n;i++){
		C[i]=S.top();
		S.pop();
		}
		}
int main(){
	char C[51];
	cin>>C;
	Reverse(C,strlen(C));
	printf("String is : %s",C); 
	}
