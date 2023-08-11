#include <iostream>
#include <cstring>

using namespace std;

int n;
long long mod = 1000000;
long long ans;
long long dp[1001][2][3];
long long  dfs(long long  day, long long  late, long long  absence) {
    if (day <= 0) 
        return 0;

    long long& ret = dp[day][late][absence];

    if (ret != -1) 
        return ret;

    if (late) {
        if (absence == 0) {
            ret = dfs(day - 1, 0, 0) + dfs(day - 1, 0, 1) + dfs(day - 1, 0, 2) + dfs(day - 1, 1, 0) + dfs(day - 1, 1, 1) + dfs(day - 1, 1, 2);
        }
        else if (absence == 1) {
            ret = dfs(day - 1, 1, 0);
        }
        else if (absence == 2) {
            ret = dfs(day - 1, 1, 1);
        }
    
        return ret%mod;
    }

    if (!late) {
        if (absence == 0) {
            ret = dfs(day - 1, 0, 0) + dfs(day - 1, 0, 1) + dfs(day - 1, 0, 2);
        }
        else if (absence == 1) {
            ret = dfs(day - 1, 0, 0);
        }
        else if (absence == 2) {
            ret = dfs(day - 1, 0, 1);
        }
        return ret%mod;
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    dp[1][0][2] = 0;
    dp[1][1][0] = 1;
    dp[1][1][1] = 0;
    dp[1][1][2] = 0;

    cin >> n;
    for (long long i = 0; i < 2; i++) {
        for (long long j = 0; j < 3; j++) {
            ans += dfs(n, i, j);
        }
    }
    ans%=mod;
    cout << ans << endl;

    return 0;
}