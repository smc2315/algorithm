#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int n,ans;
vector<int> v[1000001];
bool visited[1000001];
int dp[1000001][2];

void dfs(int num) {
	visited[num] = true;
	dp[num][0] = 0;
	dp[num][1] = 1;
	for (int i = 0; i < v[num].size(); i++) {
		if (!visited[v[num][i]]) {
			dfs(v[num][i]);
			dp[num][0] += dp[v[num][i]][1];
			dp[num][1] += min(dp[v[num][i]][0], dp[v[num][i]][1]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);

	cout << min(dp[1][0],dp[1][1]);
	return 0;
}