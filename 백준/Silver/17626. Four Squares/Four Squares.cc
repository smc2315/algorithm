#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		int mmin = INT_MAX;
		for (int j = 1; j * j <= i; j++) {
			int tmp = i - j * j;
			mmin = min(mmin, dp[tmp]);
		}
		dp[i] = mmin + 1;
	}
	cout << dp[n];

	
	return 0;


}