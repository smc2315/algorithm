#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[501][501];
string s;

int dfs(int l, int r) {
    if (l >= r) return 0;

    int &ret = dp[l][r];
    if (ret != -1) return ret;

    ret = -1;

    for (int i = l; i < r; i++) {
        ret = max(ret, dfs(l,  i) + dfs(i + 1, r));
    }

    if ((s[l] == 'a' && s[r] == 't') || (s[l] == 'g' && s[r] == 'c')) {
        ret = max(ret, dfs(l + 1, r - 1) + 2);
    }

    return ret;
}

int main() {
    cin >> s;
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, s.length() - 1);
    return 0;
}