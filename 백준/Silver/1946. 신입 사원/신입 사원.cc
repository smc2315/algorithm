#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int T,N;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		int cnt = 1;
		vector<pair<int, int>> v;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		int mmin = v[0].second;
		for (int i = 1; i < N; i++) {
			if (mmin > v[i].second) {
				mmin = v[i].second;
				cnt++;
			}
			
		}
		cout << cnt << endl;
	}
	
}