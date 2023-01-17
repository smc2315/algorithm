#include <iostream>
#include<vector>
#include <queue>



using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	vector<int> v;
	v.push_back(0);
	cin >> n >> m;
	int sum = 0;
	while (n--) {
		int t;
		
		cin >> t;
		sum += t;
		v.push_back(sum);
	}
	while (m--) {
		int i, j;
		int result = 0;
		cin >> i >> j;
		cout << v[j]-v[i-1] << "\n";
	}
	return 0;
}