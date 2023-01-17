#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    for(auto i:completion){
        m[i]++;
    }
    for(auto i: participant){
        m[i]--;
        if(m[i]<0){
            answer+=i;
            break;
        }
    }
    return answer;
}