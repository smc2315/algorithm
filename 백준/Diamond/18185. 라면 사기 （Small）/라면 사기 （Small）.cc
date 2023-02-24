#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int n,ans;
int v[10100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		if (v[i + 1] > v[i + 2]) {
			int two = min(v[i], v[i + 1] - v[i + 2]);
			ans += 5 * two;
			v[i] -= two;
			v[i + 1] -= two;

			int three = min(v[i], min(v[i + 1], v[i + 2]));
			ans += 7 * three;
			v[i] -= three;
			v[i + 1] -= three;
			v[i + 2] -= three;
		}
		else {
			int three = min(v[i], min(v[i + 1], v[i + 2]));
			ans += 7 * three;
			v[i] -= three;
			v[i + 1] -= three;
			v[i + 2] -= three;

			int two = min(v[i], v[i + 1]);
			ans += 5 * two;
			v[i] -= two;
			v[i + 1] -= two;
		
		}
		ans += 3 * v[i];
	}
	cout << ans;
	return 0;
}