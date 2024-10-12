#include <bits/stdc++.h>
 
using namespace std;
 
int N;
int dp[10001][2];
int CivilNum[10001];
bool visited[10001];
vector<int> tree[10001];
 
void dfs(int now){
    visited[now] = true;
    
    dp[now][0] = 0;
    dp[now][1] = CivilNum[now];
    
    for(int i = 0; i < tree[now].size(); i++){
        int next = tree[now][i];
        if(visited[next]) continue;
        dfs(next);
        
        dp[now][0] += max(dp[next][0], dp[next][1]);
        dp[now][1] += dp[next][0];
    }
}
 
void input(){
    int u, v;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> CivilNum[i];
    }
    for(int i = 1; i < N; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
}
 
int main(){
    input();
    dfs(1);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}