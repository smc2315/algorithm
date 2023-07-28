#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main(void){

    stack<char> oper;
    string s;
    cin >> s;
   
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << s[i];
        }
        else {
            if (s[i] == '(') {
                oper.push(s[i]);
               
            }
            else if (s[i] == ')') {
                while (oper.top() != '('&&!oper.empty()) {
                    cout << oper.top();
                    oper.pop();
                }
                oper.pop();
            }
            else if (s[i] == '+' || s[i] == '-') {
                while (!oper.empty()&&oper.top()!='(') {
                    cout << oper.top();
                    oper.pop();
                }
                oper.push(s[i]);
            }
            else {
                while (!oper.empty() && (oper.top() == '*'||oper.top()=='/') ){
                    cout << oper.top();
                    oper.pop();
                }
                oper.push(s[i]);
            }
            
        }
    }
    while (!oper.empty()) {
        cout << oper.top();
        oper.pop();
    }
    return 0;
}