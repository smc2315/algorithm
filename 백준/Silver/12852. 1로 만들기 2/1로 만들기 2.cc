#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> dp(1000001);
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	int n;
	cin >> n;
	dp[1] = { 0,0 };
	dp[2] = { 1,1 };
	dp[3] = { 1,1 };
	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			int n1 = dp[i - 1].first;
			int n2 = dp[i / 2].first;
			int n3 = dp[i / 3].first;
			int mmin = min(min(n1, n2), n3);
			if (mmin == n1) {
				dp[i] = { n1 + 1,i - 1 };
			}
			else if (mmin == n2) {
				dp[i] = { n2 + 1,i / 2 };
			}
			else
				dp[i] = { n3 + 1,i / 3 };
		}
		else if (i % 2 == 0) {
			int n1 = dp[i - 1].first;
			int n2 = dp[i / 2].first;
			if (n1 > n2) {
				dp[i] = { n2 + 1,i / 2 };
			}
			else
				dp[i] = { n1 + 1,i - 1 };
		}
		else if (i % 3 == 0) {
			int n1 = dp[i - 1].first;
			int n2 = dp[i / 3].first;
			if (n1 > n2) {
				dp[i] = { n2 + 1,i / 3 };
			}
			else
				dp[i] = { n1 + 1,i - 1 };
		}
		else {
			dp[i] = { dp[i - 1].first + 1,i - 1 };
		}

	}
	cout << dp[n].first << endl<<n<<" ";

	while (dp[n].second != 0) {
		cout << dp[n].second << " ";
		n = dp[n].second;
	}

	return 0;
}