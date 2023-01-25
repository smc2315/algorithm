#include <iostream>
#include<vector>
using namespace std;
int N;
vector<int> v;
long long dp[101][21];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	dp[0][v[0]] = 1;
	for (int i = 1; i < N-1; i++) {
		for (int j = 0; j < 21; j++) {
			if (dp[i - 1][j] == 0)
				continue;
			if (j + v[i] <= 20) {
				dp[i][j + v[i]] += dp[i - 1][j];
			}
			if (j - v[i] >= 0) {
				dp[i][j - v[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[N-2][v[N-1]];

}