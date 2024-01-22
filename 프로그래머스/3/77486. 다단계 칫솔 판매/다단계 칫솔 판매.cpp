#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, string> referr;
map<string, int> num;
map<int, string> numrev;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());
    num["-"] = -1;
    numrev[-1] = "-";
    for(int i = 0; i < enroll.size(); i++) {
        referr[enroll[i]] = referral[i];
        num[enroll[i]] = i;
        numrev[i] = enroll[i];
    }
    
    for(int i = 0; i < seller.size(); i++) {
        int amt = amount[i] * 100;
        int cur = num[seller[i]];
        while(cur != -1 && amt) {
            answer[cur] += amt - (int)(amt * 0.1);
            cur = num[referr[numrev[cur]]];
            amt *= 0.1;
        }
        

    }
    return answer;
}