
#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;
int N;

int cal(string s) {
	int ans = 0;
	int cur = 0;
	char op = '+';

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '-' || s[i] == '+' || s[i] == '\0') {
			if (op == '-') {
				ans -= cur;
				cur = 0;
			}
			else if (op == '+') {
				ans += cur;
				cur = 0;
			}
			op = s[i];
		}
		else {
			if (s[i] == ' ') {
				cur *= 10;
			}
			else cur += (s[i] - '0');
		}

	}

	return ans;
}

 void back_tracking(int n,string s) {
	if (n-1==N) {
		if (cal(s)==0) {
			for (auto c : s) {
				cout << c;
			}
			cout << endl;
		}
		return;
	}
	back_tracking(n + 1, s + " " + to_string(n));
	back_tracking( n + 1, s + "+"+to_string(n));
	back_tracking( n + 1, s + "-"+ to_string(n));



}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		
		cin >> N;
		back_tracking(2,"1");
		cout << endl;
	}
	return 0;
}