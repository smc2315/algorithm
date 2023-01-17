#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> dp(1000);
	
	for(int i=0;i<n;i++) {
		int r, g, b;
		cin >> r >> g >> b;
		if (i == 0) {
			dp[i].push_back(r);
			dp[i].push_back(g);
			dp[i].push_back(b);
		}
		else {
			dp[i].push_back(r + min(dp[i - 1][1], dp[i - 1][2]));
			dp[i].push_back(g + min(dp[i - 1][0], dp[i - 1][2]));
			dp[i].push_back(b + min(dp[i - 1][0], dp[i - 1][1]));
		}
	}
	cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));

    return 0;
}
