#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int dp[101][101];
int arr[101];

int dfs(int n, int m) {
    if (m == 0) return 0;
    if (n <= 0) return -3276800;

    int &ret = dp[n][m];

    if(ret != -1) return ret;

    ret = dfs(n - 1, m);
    int sum = 0;

    for (int i = n - 1; i >= 0; i--) {
        sum += arr[i];
        int tmp = dfs(i - 1, m - 1) + sum;
        ret = max(ret, tmp);
    }
    
    return ret;

}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));

    cout << dfs(N, M);
    return 0;
}