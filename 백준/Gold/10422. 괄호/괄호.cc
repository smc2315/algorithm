#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int T;
long long dp[5001];

int main() {
	cin >> T;
	dp[0] = 1;
	
	dp[2] = 1;
	for (int i = 4; i < 5001; i+=2) {
		for (int j = 2; j <= i; j+=2) {
			dp[i] += (dp[j - 2] * dp[i - j])%1000000007;

		}
        dp[i]%=1000000007;
		
	}
	
	while (T--) {
		int N;
		cin >> N;
		cout << dp[N] << endl;

	}
	return 0;
}