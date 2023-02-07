#include <iostream>
#include <cstring>
using namespace std;
int cnt=0,N;
int recursion(string& s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(string& s){
    return recursion(s, 0, s.size()-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        cnt = 0;
        string s;
        cin>>s;
        cout<<isPalindrome(s)<<" "<<cnt<<"\n";
    }
    return 0;
}