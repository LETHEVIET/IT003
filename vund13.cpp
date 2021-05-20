#include<bits/stdc++.h>

using namespace std;

int main()
{
    string st; cin >> st;
    string operand = "";
    //cout< st << endl;
    for (int i = 0; i < st.size(); i++){
        if (st[i] == '('){
            if (operand.size() != 0){
                cout<< operand << " operand"<< endl;
                operand = "";
            }
            cout<< "( open_parenthesis" << endl;
            continue;
        }
        if (st[i] == ')'){
            if (operand.size() != 0){
                cout<< operand << " operand"<< endl;
                operand = "";
            }
            cout<< ") close_parenthesis" << endl;
            continue;
        }
        if (st[i] == '+' || st[i] == '-' || st[i] == '*' || st[i] == '/'){
            if (operand.size() != 0){
                cout<< operand << " operand"<< endl;
                operand = "";
            }
            cout<< st[i] << " operator" << endl;
            continue;
        }
        operand+=st[i];
    }
    if (operand.size() != 0){
        cout<< operand << " operand"<< endl;
        operand = "";
    }
    return 0;
}