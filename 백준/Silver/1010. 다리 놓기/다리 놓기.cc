#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
int a, b;
int dp[31][31];


int dfs(int n,int m) {
    if (n == m || n == 0)
        return dp[n][m] = 1;
    int& ret = dp[n][m];
    if (ret != -1)
        return ret;
    ret = dfs(n - 1, m - 1) + dfs(n, m-1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        memset(dp, -1, sizeof(dp));
        cin >> a >> b;
        cout<<dfs(a,b)<<endl;
    }
    
    
    
   
    return 0;

}