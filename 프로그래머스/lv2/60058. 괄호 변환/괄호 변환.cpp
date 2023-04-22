#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool is_correct_braket(string s){
    stack<char> stk;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            stk.push(s[i]);
        }
        else{
            if(stk.empty()){
                return false;
            }
            stk.pop();
        }
    }
    if(!stk.empty())
        return false;
    return true;
    
}
string seperate_string(string s){
    if(is_correct_braket(s))
        return s;
    string u="";
    string v="";
    int cnt_left_braket = 0;
    int cnt_right_braket = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            cnt_left_braket++;
        }
        else{
            cnt_right_braket++;
        }
        if(cnt_left_braket == cnt_right_braket){
            u = s.substr(0,i+1);
            v = s.substr(i+1);
            break;
        }
    }
    cout<<u<<endl<<v<<endl;
    if(is_correct_braket(u)){
        return u+seperate_string(v);
    }
    else{
        string tmp="(";
        tmp+=seperate_string(v);
        tmp+=')';
        u=u.substr(1,u.length()-2);
        for(int i=0;i<u.length();i++){
            if(u[i] =='('){
                tmp+=')';
            }
            else{
                tmp+='(';
            }
        }
        return tmp;
        
    }
}
string solution(string p) {
    string answer = "";
    if(p=="")
        return "";
    answer = seperate_string(p);
    return answer;
}