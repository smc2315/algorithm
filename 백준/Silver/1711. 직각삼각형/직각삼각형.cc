#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<pair<long long, long long>> v;

double get_distance(long long x1, long long y1, long long x2, long long y2) {
	return (x1 - x2)*(x1 - x2) + (y2 - y1)*(y2 - y1);
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			for (int k = j + 1; k < v.size(); k++) {
				double a = get_distance(v[i].first, v[i].second, v[j].first, v[j].second);
				double b = get_distance(v[j].first, v[j].second, v[k].first, v[k].second);
				double c = get_distance(v[i].first, v[i].second, v[k].first, v[k].second);
				
				if ((a == b + c) || (b == a + c) || (c == a + b))
					cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}