#include <iostream>
#include<vector>
#include <map>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		map<string, int> mp;
		int m;
		cin >> m;
		while (m--) {
			string v, k;
			cin >> v >> k;
			mp[k]++;
		}
		int result = 1;
		for (auto i : mp) {
			//cout << i.first << " " << i.second<<endl;
			result *= (i.second+1);
			//cout << result<<endl;
		}
		cout << result - 1<<endl;
	}


	return 0;
}