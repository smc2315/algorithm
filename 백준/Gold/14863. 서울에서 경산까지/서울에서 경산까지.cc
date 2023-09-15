#include <iostream>
#include <cstring>

using namespace std;

int N,K;
pair<int,int> walk[101];
pair<int,int> bike[101];

int dp[101][100001];

int dfs(int n, int t){
    if(n==N){
        return 0;
    }
    int& ret = dp[n][t];
    if(ret!=-1)
        return ret;
    ret = -1e9;
    if(t >= walk[n].first)
        ret = max(ret, dfs(n+1,t-walk[n].first)+walk[n].second);
    if(t >= bike[n].first)
        ret = max(ret, dfs(n+1,t-bike[n].first)+bike[n].second);
    return ret;
}

int main() {
    cin>>N>>K;

    for(int i=0;i<N;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        walk[i] = {a,b};
        bike[i] = {c,d};
    }
    memset(dp, -1 ,sizeof(dp));
    cout<<dfs(0, K);
}