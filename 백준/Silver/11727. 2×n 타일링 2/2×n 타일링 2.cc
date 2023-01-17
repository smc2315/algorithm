#include <iostream>
#include<vector>
#include <queue>



using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> dp;
	dp.push_back(1);
	dp.push_back(3);
	for (int i = 2; i < n; i++) {
		dp.push_back((dp[i - 1] + dp[i - 2]*2)%10007);
	}
	cout << dp[n - 1];
	
	return 0;
}