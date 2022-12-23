#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
set<long long> sums;
vector<long long> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
		
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		int val = v[i];     
		int l = 0;
		int r = N - 1;
		int sum;
		while (l < r) {
			sum = v[l] + v[r];
			if (sum == val) {
				if (l != i && r != i) {
					cnt++;
					break;
				}
				else if (l == i) l++;
				else if (r == i) r--;
			}
			else if (sum < val) l++;
			else r--;
		}
	}
	cout << cnt;
	return 0;
}
