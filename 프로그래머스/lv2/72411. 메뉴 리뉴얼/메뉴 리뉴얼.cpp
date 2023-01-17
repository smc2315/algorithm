#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<map<string,int>> v;

bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second > b.second;
}

void findCom(string s,string result,int cur, int n,int size){
    if(n==0){
        v[size][result]++;
        return;
    }
    
    for(int i=cur;i<s.size();i++){
        string tmp ="";
        tmp = result;
        tmp+=s[i];
        findCom(s,tmp,i+1,n-1,size);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto j:course){
        map<string,int> m;
        v.push_back(m);
    }
    for(auto i : orders){
        sort(i.begin(),i.end());
        for(int j=0;j<course.size();j++){
            if(course[j]<=i.size()){
                findCom(i,"",0,course[j],j);
            }
        }
    }
    for(int i=0;i<v.size();i++){
        if(v[i].empty())
            continue;
        vector<pair<string,int>> tmp(v[i].begin(),v[i].end());
        sort(tmp.begin(),tmp.end(),cmp);
        int n = tmp[0].second;
        if(n<2)
            continue;
        int j=0;
        while(tmp[j].second==n){
            answer.push_back(tmp[j].first);
            j++;
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}