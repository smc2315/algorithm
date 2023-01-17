#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;

bool visited[9];

void sequence(int cnt, vector<int> s) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << s[i] << " ";
		}
		cout << endl;
		
		return;
	}
	int tmp = -1;
	for (int i = 0; i < n; i++) {
		
		if (!visited[i]&&v[i]!=tmp) {
			
			s.push_back(v[i]);
			visited[i] = true;
			tmp = v[i];
			sequence(cnt + 1, s);
			visited[i] = false;
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