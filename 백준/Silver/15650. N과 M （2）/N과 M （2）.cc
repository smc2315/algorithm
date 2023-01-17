#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

int n, m;

void sequence(int cnt, string s) {
	if (cnt == 0) {
		for (int i = 1; i < s.size(); i++) {
			cout << s[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = s[s.size()-1] - '0' + 1; i <= n; i++) {
		sequence(cnt - 1, s + to_string(i));
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	sequence(m,"0");
	

	return 0;
}