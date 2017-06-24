#include <iostream>
#include <string>
#include <stack>
using namespace std;

int AreBal(char opening,char closing){
	if(opening=='[' && closing ==']')return 1;
	else if(opening=='{' && closing =='}')return 1;
	else if(opening=='(' && closing ==')')return 1;
	else return 0;
	}
int AreParanthesesBalanced(string exp){
	stack<char> s;
	int len=0;
	for(int j=1;exp[j]!='\0';j++){
		len+=j;
		}
	for(int i=0;i<len;i++){
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			s.push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{	if(!s.empty() && AreBal(s.top(), exp[i])){
			s.pop();
			}
			else return 0;
			}
		}
		return s.empty()?1:0;
}
int main()
{
	string exp;
	cout<<"Enter your expression :"<<endl;
	cin>>exp;
	if(AreParanthesesBalanced(exp))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
	return 0;
}

