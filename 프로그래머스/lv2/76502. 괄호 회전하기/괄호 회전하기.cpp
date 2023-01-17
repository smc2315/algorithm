#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool check(string s){
    stack<char> stk;
    for(auto c: s){
        if(c == '('||c=='{'||c=='['){
            stk.push(c);
        }
        else{
            if(c==')'){
                if(stk.empty()||stk.top()!='(')
                    return false;
                stk.pop();
            }
            else if(c=='}'){
                if(stk.empty()||stk.top()!='{'){
                    return false;
                }
                stk.pop();
            }
            else{
                if(stk.empty()||stk.top()!='['){
                    return false;
                }
                stk.pop();
            }
                
            
        }
    }
    if(!stk.empty())
        return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.size();i++){
        if(check(s)){
            answer++;
        }
        s=s+s[0];
        s = s.substr(1,s.size()-1);
        
        
    }
    return answer;
}