#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
string S,T;
map<string, bool> m;
bool solve(string s) {
	if (s == S)
		return true;
	if (s.length() < S.length())
		return false;
	if (m[s])
		return false;
	string A="",B="";
	if (s[s.length()-1] == 'A') {
		A = s;
		A.erase(s.length() - 1);
	}
	if (s[0] == 'B') {
		B = s;
		reverse(B.begin(), B.end());
		B.erase(s.length() - 1);
	}
	
	
	
	return m[s] = solve(A) || solve(B);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> S >> T;

	cout<<solve(T);

	return 0;
}