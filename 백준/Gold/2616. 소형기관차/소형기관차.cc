#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int N,M;
int dp[4][50001];
int v[50001];


int DP(int cnt, int len) {
    if (cnt == 4 || len> N)
        return 0;
    int& ret = dp[cnt][len];
    if (ret != -1)
        return ret;
    ret = 0;

    ret = max(DP(cnt, len + 1), DP(cnt + 1, len + M) + v[len] - v[len - M]);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        v[i] = tmp + v[i - 1];
    }
    cin >> M;
    memset(dp, -1, sizeof(dp));
    
    cout<<DP(1,M);

    return 0;

}