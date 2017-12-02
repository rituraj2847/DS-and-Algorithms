#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct Stack{
	int top;
	unsigned capacity;
	int* array;
};
int Prec(char c){
	switch(c){
		case '+':
		case '-':
				return 1;
		case '*':
		case '/':
				return 2;
		case '^':
				return 3;
	}
}
int IsOperator(char c){
		return (c=='+' || c=='-' || c=='/' || c=='^' || c=='*')? 1:0;
	}
int IsOperand(char c){
	return (c>=48 && c<=57)? 1:0;
	}
void pop(Stack* stack){
	--stack->top;
}
void push(Stack* stack, char c){
	stack->array[++stack->top] = c;
}
char peek(Stack* stack){
	return stack->array[stack->top];
}
bool IsEmpty(Stack* stack){
	return (stack->top == -1)?1:0;
}
void InfixToPostfix(int size, string exp){
	string ns = "";
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->array = (int*)malloc(size);
	stack->capacity = size;
	stack->top = -1;
	for(int i=0;i<size;i++){
		if(IsOperand(exp[i])){
			ns += exp[i];
		}
		else if(IsOperator(exp[i])){
			while(peek(stack) !='(' && Prec(exp[i]) <= Prec(peek(stack))){
				ns += peek(stack);
				pop(stack);
			}
			push(stack, exp[i]);
		}
		else if(exp[i] == '('){
			push(stack, exp[i]);
		}
		else if(exp[i] == ')'){
			while(peek(stack) != '('){
				ns += peek(stack);
				pop(stack);
			}
			pop(stack);
		}
	}
	while(!IsEmpty(stack)){
		ns += peek(stack);
		pop(stack);
	}
	cout<<"The postfix expression is: "<<ns<<"\n";
}
int main(){
	string exp="2/(1-3)+8*4";
	InfixToPostfix(exp.size(), exp);
}	
