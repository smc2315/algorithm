#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

string get_num(int n, int k){
    string s = "0";
    while(n>0){
        s+=to_string(n%k);
        n/=k;
    }
    s+="0";
    reverse(s.begin(), s.end());
    return s;
}

bool is_prime(string s){
    long long num = stol(s);
    if(num <= 1)
        return false;
    for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                return false; 
            }
        }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string s = get_num(n,k);
    string tmp ="";
    for(int i=0;i<s.size();i++){
        if(s[i] == '0'){
            if(tmp != ""){
                if(is_prime(tmp)){
                    answer++;
                }
            }
            tmp = "";
        }
        else{
            tmp+=s[i];
        }
    }
    return answer;
}