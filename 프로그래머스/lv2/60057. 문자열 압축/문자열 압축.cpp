#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int cut(int n, string s){
    string tmp = s.substr(0,n);
    int ret = s.size();
    
    bool flag = false;
    int cnt = 1;
    for(int i=n;i<s.size();i+=n){
        string cur = s.substr(i,n);
        if(cur == tmp){
            flag=true;
            ret-=n;
            cnt++;
        }
        else{
            if(flag){
                ret+=(int)log10(cnt)+1;
                flag = false;
                cout<<n<<" "<<cnt<<" "<<(int)log10(cnt)+1<<" "<<ret<<endl;
            }
            cnt = 1;
            
        }
        tmp = cur;
    }
    if(flag){
        ret+=(int)log10(cnt)+1;
    }
    //cout<<n<<" "<<ret<<endl;
    return ret;
}

int solution(string s) {
    int answer = s.size();
    int size = s.size();
   
    for(int i=1;i<=size/2+1;i++){
        
        answer = min(answer,cut(i,s));
        
    }
    return answer;
}