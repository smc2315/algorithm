#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

long long N, Hatk;

vector<tuple<int, int, int>> v;

bool simulate(long long h) {
	long long atk = Hatk;
	long long maxh = h;
	for (int i = 0; i < N; i++) {
		auto cur = v[i];
		
		if (get<0>(cur) == 1) {
			if (get<2>(cur) % atk == 0) 
				h -= get<1>(cur) * (get<2>(cur)/atk-1);
			else 
				h -= get<1>(cur) * (get<2>(cur) / atk);
			if (h <= 0) 
				return false;
		}
		else {
			atk += get<1>(cur);
			h = min(maxh,h+get<2>(cur));
		}
	}
	return true;

}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Hatk;
	for (int i = 0; i < N; i++) {
		int t, a, h;
		cin >> t >> a >> h;
		v.push_back({ t,a,h });
	}

	long long l = 1;
	long long r = 1e18;
	long long ans = 0;
	while (l <= r){

		long long mid = (l + r) / 2;
		if (simulate(mid)){
			
			ans = mid;
			r = mid - 1;
		}

		else
			l = mid + 1;

	}
	cout << ans;
	return 0;
}