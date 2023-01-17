#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> arr;
	int dp[1001] = { 0, };
	int n; 
	cin >> n;
	int mmax = 1;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		arr.push_back(m);
	}
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				if (dp[i] > mmax)
					mmax = dp[i];
			}
		}
	}
	cout << mmax;
	

	return 0;
}