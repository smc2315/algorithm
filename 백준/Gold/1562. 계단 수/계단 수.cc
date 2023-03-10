#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

long long dp[10][100][1<<11];

int N;
int dfs(int n,int m,int bit) {
	
	if (m == N) {
	
		if (bit == (1 << 10) - 1){
			
			return 1;
		}
		return 0;
	}
	long long& ret = dp[n][m][bit];
	if (ret != -1)
		return ret;
	int next1 = n - 1;
	int next2 = n + 1;
	ret = 0;
	if (next1 >= 0) {
		ret += dfs(next1,m+1,bit|(1<<(next1)))%1000000000;
	}
	if (next2 <= 9) {
		ret += dfs(next2,m+1,bit|(1<<(next2)))%1000000000;
	}
	return ret;

}

void solve() {
	
	cin >> N;
	memset(dp, -1, sizeof(dp));
	long long ans=0;
	for (int i = 1; i <= 9; i++) {
		
		ans += dfs(i, 1,1<<i)%1000000000;
	}
	
	cout<<ans%1000000000;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}