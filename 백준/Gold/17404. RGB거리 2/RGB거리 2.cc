#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N;
int rgb[1001][3];
int dp[1001][3];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int mmin = 1e9;
	for (int i = 1; i <= N; i++) {
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)dp[1][j] = rgb[1][j];
			else dp[1][j] = 1e9;
		}
		for (int j = 2; j <= N; j++) {
			dp[j][0] = rgb[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = rgb[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = rgb[j][2] + min(dp[j - 1][1], dp[j - 1][0]);
		}
		for (int j = 0; j < 3; j++) {
			if (i == j)continue;
			mmin = min(mmin, dp[N][j]);
		}
	}
	

	cout << mmin;
	return 0;
}