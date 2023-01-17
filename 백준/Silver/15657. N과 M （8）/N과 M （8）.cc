#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;

void sequence(int cnt, vector<int> s) {
	if (cnt == m) {
		for (int i = 0; i < s.size(); i++) {
			cout << s[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.push_back(v[i]);
			sequence(cnt + 1, s);
			s.pop_back();
		}
		else if (s[s.size()-1]<=v[i]) {
			s.push_back(v[i]);
			sequence(cnt + 1, s);
			s.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	vector<int> s;
	sequence(0, s);



	return 0;
}