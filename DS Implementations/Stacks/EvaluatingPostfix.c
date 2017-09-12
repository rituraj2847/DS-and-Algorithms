#include <stdio.h>
#include <ctype.h>
int stack[30];
int top=-1;
void Push(int d){
	stack[++top]=d;
	printf("%d\n",stack[top]);
	}
int Pop(){
		return stack[top--];
		}
int main()
{
	char exp[]="23*5+";
	int n1,n2,i=0;
	while(exp[i]!='\0'){
		
		if(isdigit(exp[i])){
			Push(exp[i]-48);
			}
		else {
			n1=Pop();
			n2=Pop();
		switch(exp[i]){
			case '*': Push(n1*n2);
					  break;
			case '+': Push(n1+n2);
			          break;
			case '-': Push(n1-n2);
			          break;
			case '/': Push(n1/n2);
			          break;
			default : break;
			}
			}
		i++;
		}
	printf("%d",stack[top]);
	return 0;
}

