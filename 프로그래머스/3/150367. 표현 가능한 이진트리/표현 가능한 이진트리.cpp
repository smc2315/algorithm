#include <string>
#include <vector>
#include <iostream>
using namespace std;

string int_to_bin(long long n) {
    string s = "";
    while (n > 0) { 
        s = to_string(n % 2) + s; 
        n = n / 2;  
    }
    int idx = 2;
    string ret = s;
    while (true) {
        if (s.length() <= idx - 1) break;
        idx *= 2;
    }
    for (int i = 0; i < idx - 1 - s.length(); i++) ret = "0" + ret;
    return ret;
}

bool is_all_zero(string bin) {
    for(auto s : bin){
        if(s == '1')
            return false;
    }
    return true;
}
bool check_possible(string bin) {
    int len = bin.length();
    if(len == 1 || is_all_zero(bin)){
        return true;
    }
    if(bin[len/2] == '1' && check_possible(bin.substr(0,len/2)) && check_possible(bin.substr(len/2+1))){
        return true;
    }
    return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(auto number : numbers){
        string bin = int_to_bin(number);
        if(check_possible(bin)) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }
        }
    return answer;
}