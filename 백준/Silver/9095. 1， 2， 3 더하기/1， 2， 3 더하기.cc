#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	
	while (N--) {
		int dp[11] = { 0, };
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		int M;
		cin >> M;
		if (M == 1)
			cout << 1<<"\n";
		else if (M == 2)
			cout << 2<<"\n";
		else {
			for (int i = 4; i <= M; i++) {
				dp[i] += dp[i - 1];
				dp[i] += dp[i - 2];
				dp[i] += dp[i - 3];
			}
			cout << dp[M]<<"\n";
		}
	}
	return 0;


}