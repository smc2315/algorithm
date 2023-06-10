#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long T;
int n, m;
int arr1[1001];
int arr2[1001];
vector<long long> v1;
vector<long long> v2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}

	for (int i = 0; i < n; i++) {
		long long sum = arr1[i];
		v1.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += arr1[j];
			v1.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++) {
		long long sum = arr2[i];
		v2.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += arr2[j];
			v2.push_back(sum);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	long long ans = 0;

	for (int i = 0; i < v1.size(); i++) {
		int low = lower_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();
		int high= upper_bound(v2.begin(), v2.end(), T - v1[i]) - v2.begin();

		ans += high - low;
	}

	cout << ans << endl;
	return 0;
}