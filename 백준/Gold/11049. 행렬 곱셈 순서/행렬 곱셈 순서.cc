#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N;
pair<int, int> v[501];
int dp[501][501];
int DP(int s, int e) {
	if (s == e) 
		return dp[s][e] = 0;
	
	int &ret = dp[s][e];

	if (ret != -1)
		return ret;

	for (int i = s; i < e; i++) {
		int tmp = DP(s, i) + DP(i + 1, e) + v[s].first*v[i].second*v[e].second;
		ret = (ret==-1)?tmp: min(ret, tmp);
	}
	return ret;

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N; i++) {
		int r, c;
		cin >> r >> c;
		v[i] = { r,c };
	}
	cout<< DP(1,N);
	return 0;
}