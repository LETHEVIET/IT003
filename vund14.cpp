/* C++ implementation to convert
infix expression to postfix*/

#include<bits/stdc++.h>
using namespace std;

int prec(string c) {
	if(c == "^")
		return 3;
	else if(c == "*" || c == "/")
		return 2;
	else if(c == "+" || c == "-")
		return 1;
	else
		return -1;
}

void infixToPostfix(vector<string> s) {

	stack<string> st; 
	string result;

	for(int i = 0; i < s.size(); i++) {
		string c = s[i];

		if( (s[i][0] >= '0') && (s[i][0] <= '9') )
			result += c + " ";

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if(c == "(")
			st.push("(");

		// If the scanned character is an ‘)’,
		// pop and to output string from the stack
		// until an ‘(‘ is encountered.
		else if(c == ")") {
			while(!st.empty() && st.top() != "(")
			{
				string temp = st.top();
				st.pop();
				result += temp  + " ";
			}
			st.pop();
		}

		//If an operator is scanned
		else {
			while(!st.empty() && prec(s[i]) <= prec(st.top())) {
				string temp = st.top();
				st.pop();
				result += temp  + " ";
			}
			st.push(c);
		}
	}

	// Pop all the remaining elements from the stack
	while(!st.empty()) {
		string temp = st.top();
		st.pop();
		result += temp  + " ";
	}

	cout << result << endl;
}

//Driver program to test above functions
int main() {

	string st; cin >> st;
	vector<string> a;
    string operand = "";
    //cout< st << endl;
    for (int i = 0; i < st.size(); i++){
        if (st[i] == '(' || st[i] == ')' || st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/'){
            if (operand.size() != 0){
				a.push_back(operand);
                operand = "";
            }
			string s (1, st[i]);
			a.push_back(s);
            continue;
        }
        operand+=st[i];
    }
    if (operand.size() != 0){
		a.push_back(operand);
        operand = "";
    }


	infixToPostfix(a);
	return 0;
}
