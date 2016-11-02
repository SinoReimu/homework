#include <iostream>
#include <cstring>
#include <cmath>

#include "includes/stack.h"
#include "includes/function.h"

using namespace std;

string *vars = new string[10];
int index_vars_a = 0;

string deNot (string a) {
	string a2 = "";
	for (int i=1;i<a.length();i++) a2+=a[i];
	return a2;
}

int getVar (string a) {
	for (int i=0;i<index_vars_a;i++) {
		if (vars[i] == a) return i;
	}
	if (a.find("~") != string::npos) {
		int index=getVar(deNot(a));
		vars[index+5] = a; 
    	return 5+index;
	} else {
		vars[index_vars_a] = a;
		index_vars_a++;
		return index_vars_a-1;
	}
}

function f[] = {choose, tree, exit};

bool check (string s) {
	bool *values = new bool[index_vars_a];
	bool *result = new bool[(int)pow(2, index_vars_a)];
	bool finalA = false,finalB = true;
	cout << "value map:" << endl;
	for (int i=0;i<pow(2, index_vars_a);i++) {
		int temp = i;
		for (int j=0;j<index_vars_a;j++) {
			bool v;
			if (temp%2==1) v = true;
			else v = false;
			values[j] = v;
			cout << temp%2 << "  ";
			temp = temp/2;
		}
		result[i] = cal(s, values);
		finalB &= result[i];
		finalA |= result[i];
		cout << result[i] << endl;
	}
	if (finalB == true) 
		cout << "all true" << endl;
	else if (finalA == false) 
		cout << "all false" << endl;
	else {
		cout << "not yet" << endl;
		cout << "now you can\n1)choose a value map\n2)view tree of expression\n3)exit\nchoose one:";
		int select;
		cin >> select;
		f[select-1](s, vars, index_vars_a);
	}
}

int main () {

	string temp = "";
	string out = "";
	string expression;
	Stack<char> stack;
	
	cout << "please input a expression : ";
	cin >> expression;
	for(int i=0;i<expression.length();i++) {
		char c = expression[i];
		if (c=='('||c==')'||c=='&'||c=='|'){
			if (temp!="") {
				char a = (char)(48+getVar(temp));
				out+=a;
				temp = "";
			}
			if (c=='(')
				stack.push(c);
			else if (c==')') {
				for (;;){
					Node<char>* n2 = stack.front();
					if (n2==NULL) break;
					if (n2->c=='(') {stack.pop();break;}
					char s = n2->c;
					out+=s;
					stack.pop();
				}
			}
			else if (c=='&') {
				Node<char>* n = stack.front();
				if (n==NULL) {stack.push(c);continue;}
				char s = n->c;
				if (s=='|'||s=='(') stack.push(c);
				else {
					out+=s;
					stack.pop();
					stack.push(c);
				}
			}
			else if (c=='|') {
				Node<char>* n = stack.front();
				if (n==NULL||n->c=='(') {stack.push(c);continue;}
				char s = n->c;
				out+=s;
				stack.pop();
				stack.push(c);
			}
		} else
			temp+=c;
	}
	if (temp!="")
		out+=(char)(48+getVar(temp));
	while (stack.front()!=NULL) {
		out+=stack.front()->c;
		stack.pop();
	}
	
	cout << out << endl;
	check(out);	
	return 0;
}

