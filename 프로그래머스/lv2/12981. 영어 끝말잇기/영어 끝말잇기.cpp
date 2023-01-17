#include <string>
#include <vector>
#include <iostream>
#include <map>
#include<cmath>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int index = 1;
    map<string,bool> m;
    string tmp = words[0];
    m[words[0]] = true;
    if(tmp.size()==1){
        answer.push_back(1);
        answer.push_back(1);
        return answer;
        }
    for(int i=1;i<words.size();i++){
        if(words[i].size()==1){
            answer.push_back(index+1);
            answer.push_back(ceil(double(i+1)/n));
            return answer;
        }
        if(m[words[i]]==true){
            answer.push_back(index+1);
            answer.push_back(ceil(double(i+1)/n));
            return answer;
        }
        
        if(tmp[tmp.size()-1]!=words[i][0]){
            cout<<index+1<<" "<<i<<endl;

            answer.push_back(index+1);
            answer.push_back(ceil(double(i+1)/n));
            
            return answer;
        }
        m[words[i]]=true;
        index = (index+1)%(n);
        tmp = words[i];
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}