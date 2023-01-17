#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >> N>>M;
	map<string, string> m;
	while (N--) {
		string s1;
		string s2;
		cin >> s1 >> s2;
		m.insert({ s1,s2 });
	}
	while (M--) {
		string s;
		cin >> s;
		cout << m[s]<<"\n";
	}
	return 0;


}