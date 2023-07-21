#include <string>
#include <vector>
#include<algorithm>
#include <iostream>

using namespace std;

int arr[501];
int cur[501];
vector<pair<double,int>> v;

bool compare(pair<double, int>a, pair<double, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    for(int i=0;i<stages.size();i++){
        cur[stages[i]]++;
        for(int j=0;j<=stages[i];j++){
            arr[j]++;
        }
    }
    
    for(int i=1;i<=N;i++){
        if(arr[i] == 0){
            v.push_back({0,i});
            continue;
        }
        v.push_back({(double)cur[i]/arr[i],i});
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<N;i++){
        answer.push_back(v[i].second);
    }
    
    return answer;
}