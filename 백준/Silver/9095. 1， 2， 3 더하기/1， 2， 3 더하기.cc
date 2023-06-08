#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int T;
int N;
int dp[12];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		
	}

	while (T--) {
		cin >> N;
		cout << dp[N] << endl;
	}
	return 0;
}