#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
int ssize;
vector<int> v;

bool check(vector<vector<string>>& vv,int bit){
    unordered_set<string> s;
    for(int i=0;i<vv.size();i++){
        string tmp = "";
        for(int j=0;j<ssize;j++){
            if(((1<<j)&bit) == (1<<j)){
                tmp+=vv[i][j];
            }
        }
        s.insert(tmp);
    }
    if(vv.size()!=s.size())
        return false;
    return true;
}

void dfs(int s,int n,int cnt, int bit,vector<vector<string>>& vv){
    for(int i=0;i<v.size();i++){
        if((v[i]&bit) == v[i])
            return;
    }
    if(cnt == n){
        if(check(vv,bit)){
            v.push_back(bit);
        }
        return;
    }
    for(int i=s;i<ssize;i++){
        dfs(i+1,n,cnt+1,bit|(1<<i),vv);
    }
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    ssize = relation[0].size();
    for(int i=1;i<=ssize;i++){
        dfs(0,i,0,0,relation);
    }
    return answer = v.size();
}