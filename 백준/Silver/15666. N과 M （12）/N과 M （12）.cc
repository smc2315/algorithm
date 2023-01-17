#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector<int> v;


int tmp2 = -1;
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
		
		if (tmp!=v[i]&&v[i]>=tmp2) {
			
			s.push_back(v[i]);
			
			tmp = v[i];
			tmp2 = v[i];
			sequence(cnt + 1, s);
			tmp2 = -1;
			
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