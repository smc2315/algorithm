#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
const int MAX_N = 101;
const int MAX_PRICE = 100'001;
int N;
vector<pii> coins;
int cache[MAX_N][MAX_PRICE];

int dp(int idx, int price) {
	if (price < 0) return 0;
	if (idx == N) return price == 0;

	int& ret = cache[idx][price];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i <= coins[idx].second; i++) {
		//ret = max(ret, dp(idx + 1, price - coins[idx].first * i));
		if (dp(idx + 1, price - coins[idx].first * i)) {
			return 1;
		}
	}
	return ret;
}

int main() {
	for (int t = 0; t < 3; t++) {
		int sum = 0, ans;

		cin >> N;
		coins.resize(N);

		for (int i = 0; i < N; i++) {
			cin >> coins[i].first >> coins[i].second;
			sum += coins[i].first * coins[i].second;
		}


		if (sum % 2) {
			ans = 0;
		}
		else {
			memset(cache, -1, sizeof(cache));
			ans = dp(0, sum / 2);
		}
		cout << ans << endl;
	}
	return 0;
}