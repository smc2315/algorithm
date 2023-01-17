#include <iostream>
#define MOD 1000000007
using namespace std;

long long power(long long n, long long m) {
	long long ret = 1;
	while (m) {
		if (m & 1) ret = ret * n % MOD;
		m = m / 2;
		n = n * n % MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int M; cin >> M;
	long long answer = 0;

	while (M--) {
		int n, s; cin >> s >> n;
		answer += (n * (power(s, MOD - 2))) % MOD;
	}

	cout << answer % MOD;

	return 0;
}