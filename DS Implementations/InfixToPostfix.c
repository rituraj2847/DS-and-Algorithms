#include <stdio.h>
#include <string.h>
char stack[20];
int top=-1;
void Push(char c){
	stack[++top]=c;
	}
int Pop(){
	return stack[top--];
	}
int IsEmpty(){
	if(top==-1) {
		return 1;
		}
	else return 0;
	}
int IsOperator(char c){
	if(c=='+' || c=='-' || c=='/' || c=='*'){
		return 1;
		}
		else return 0;
	}
int HasHigherPrec(char c, char d){
	if((c=='+' && d=='*') || (c=='-' && d=='*') || (c=='+' && c=='/') || (c=='-' && c=='/')){
		return 1;
		}
 		else 
 		return 0;
	}
int IsOperand(char c){
	if(c>=48 && c<=57){
		return 1;}
	else return 0;
	}
int main()
{
	char exp[9]="2+3*3-6*2";
	char pf[20];
	int j=0;
	for(int i=0;i<9;i++){
		if(IsOperand(exp[i])){
		pf[j++]=exp[i];
		}
		else if(IsOperator(exp[i])){
			while(!(IsEmpty()) && HasHigherPrec(exp[i],stack[top])){
				pf[j++]=Pop();
				}
			Push(exp[i]);
		}
		else {
			Push(exp[i]);
		}
		}
		for(int i=0;i<=top;i++){
			pf[j++]=Pop();
			}
		
		printf("%s",pf);			
	return 0;
}

