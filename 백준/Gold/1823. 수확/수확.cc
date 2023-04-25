#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int v[2001];
int dp[2001][2001];

int dfs(int l, int r, int day) {
	if (l > r) 
		return 0;
	int& ret = dp[l][r];
	if (ret != -1) 
		return ret;
	return ret = max(v[l] * day + dfs(l + 1, r, day + 1), v[r] * day + dfs(l, r - 1, day + 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, N - 1,1);
	return 0;
}