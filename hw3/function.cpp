#include <iostream>
#include <cstring>
#include "includes/stack.h"
#include "includes/tree.h"
#include "includes/function.h"

using namespace std;

bool cal (string s, bool* values) {
	Stack<bool> stack;  
	for (int i=0;i<s.length();i++) {
		char d = s[i];
		if (d=='&'||d=='|') {
			bool v1 = stack.front()->c;
			stack.pop();
			bool v2 = stack.front()->c;
			stack.pop();
			bool v3;
			if (d=='&') v3 = v1&v2;
			else if (d=='|') v3 = v1|v2;
			stack.push(v3);
		} else {
			int index = d - 48;
			bool val;
			if (index>4) 
				val = !values[index-5];
			else 
				val = values[index];
			stack.push(val);	
		}
	}
	return stack.front()->c;
}

void exit (string a, string *b, int c) {
	exit(0);
}

void choose(string a, string *b, int c) {
	bool *v = new bool[c];
	for (int i=0;i<c;i++) {
		cout << "please input value of " << b[i] << "0 or 1(other)";
		cin >> v[i];
	}
	cout << "the result is " << cal(a, v);
}

void tree(string a, string *b, int c) {
	
}
