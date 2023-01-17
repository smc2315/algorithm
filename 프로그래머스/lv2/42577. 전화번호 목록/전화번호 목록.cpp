#include <string>
#include <vector>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string,int> m;
    for(auto i:phone_book){
        m[i] = 1;
    }
    for(auto i:phone_book){
        string tmp = "";
        for(auto j:i){
            tmp+=j;
            if(m[tmp]&&tmp!=i){
                answer=false;
                break;
            }
        }
    }
    return answer;
}