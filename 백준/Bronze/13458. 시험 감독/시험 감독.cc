#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	int n;
	cin >> n;
	long long ans = 0;
	vector<int> Ai;
	for (int i = 0; i < n; i++) {
		int A;
		cin >> A;
		Ai.push_back(A);
	}
	int B, C;
	cin >> B >> C;
	for (auto i : Ai) {
		ans++;
		i = i - B;
		if (i > 0) {
			ans += i / C;
		}
		if (i % C > 0) {
			ans++;
		}
	}
	cout << ans<<endl;

	return 0;
}