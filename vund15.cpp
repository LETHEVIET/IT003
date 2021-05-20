/* C++ implementation to convert
infix expression to postfix*/

#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    return (s[0] >= '0') && (s[0] <= '9') ;
}

int str2int(string s){
    stringstream geek(s);
    int x = 0;
    geek >> x;

    return x;
}

int main() {

	string st;
    getline(cin, st);
	vector<string> a;
    string operand = "";
    //cout< st << endl;
    for (int i = 0; i < st.size(); i++){
        if (st[i] == ' '){
            if (operand.size() != 0){
		        a.push_back(operand);
                operand = "";
            }
            continue;
        }
        if (st[i] == '(' || st[i] == ')' || st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/'){
            
			string s (1, st[i]);
			a.push_back(s);
            continue;
        }else
            operand+=st[i];
    }

    stack<int> stk;
    for (int i = 0; i < a.size(); i ++){
        if (check(a[i])){
            stk.push(str2int(a[i]));
            continue;
        }
        if (a[i] == "+"){
            int tmp = stk.top();
            stk.pop();
            //cout<< stk.top() << a[i] << tmp << "=";
            stk.top() = tmp + stk.top();
            //cout<< stk.top() << endl;
            continue;
        }     
        if (a[i] == "-"){
            int tmp = stk.top();
            stk.pop();
            //cout<< stk.top() << a[i] << tmp << "=";
            stk.top() =stk.top() - tmp;
            //cout<< stk.top() << endl;

            continue;
        }    
        if (a[i] == "*"){
            int tmp = stk.top();
            stk.pop();
            //cout<< stk.top() << a[i] << tmp << "=";
            stk.top() = tmp * stk.top();
            //cout<< stk.top() << endl;

            continue;
        }    
        if (a[i] == "/"){
            int tmp = stk.top();
            stk.pop();
            //cout<< stk.top() << a[i] << tmp << "=";
            stk.top() = stk.top() / tmp;
            //cout<< stk.top() << endl;

            continue;
        }       
    }

    cout<< stk.top();
	return 0;
}
