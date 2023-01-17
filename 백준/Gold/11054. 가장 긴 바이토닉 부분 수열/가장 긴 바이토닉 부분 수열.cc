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
	int dp2[1001] = { 0, };
	int n; 
	int result =1 ;
	cin >> n;
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
				
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = n-1; j >i; j--) {
			if (arr[j] < arr[i]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
				
			}
		}
		dp[i] = dp[i] + dp2[i] - 1;
		if (result < dp[i]) {
			result = dp[i];
		}
	}
	
	cout << result;


	return 0;
}