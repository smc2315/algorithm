#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(string s) {
    vector<int> answer;
    
    int arr[100001] = {0,};
    string tmp="";
    
    for(int i=1;i<s.size()-1;i++){
        
        if(s[i] != '{' && s[i] != '}' && s[i] != ','){
            tmp+=s[i];
            if (s[i+1] != ',' && s[i+1] != '}') 
                continue;
            arr[stoi(tmp)]++;
            
        }
        tmp="";
        
    }
    vector<pair<int,int>> v;
    for(int i=0;i<100001;i++){
        if(arr[i]){
            v.push_back({arr[i],i});
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(auto i : v){
        answer.push_back(i.second);
    }
    return answer;
}
