#include<iostream>
#include<vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, M;
vector<int> v;
int dp[1001][1001];

int DP(int name, int len) {
    if (name >= N) {
        return 0;
    }
    int& res = dp[name][len];

    if (res != -1) {
        return res;
    }
    res = (M - len + 1) * (M - len + 1) + DP(name + 1, v[name] + 1);

    if (len + v[name] <= M)
        res = min(res, DP(name + 1, len + v[name] + 1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    memset(dp, -1, sizeof(dp));
    cout << DP(0, 0) << endl;
    return 0;
}