#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int dp[301];

int main() 
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v.push_back(m);
	}
	dp[0] = v[0];
	dp[1] = max(v[1], v[0] + v[1]);
	dp[2] = max(v[0] + v[2], v[1] + v[2]);
	for (int i = 3; i < n; i++)
		dp[i] = max(v[i] + dp[i - 2], v[i] + v[i - 1] + dp[i - 3]);
	cout << dp[n-1];
	return 0;
}