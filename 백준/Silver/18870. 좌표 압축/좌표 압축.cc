#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> v;
	vector<int> v2;
	map<int,int> m;
	while (n--) {
		int m;
		cin >> m;
		v.push_back(m);
		v2.push_back(m);
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	int tmp = 1000000001;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != tmp) {
			m.insert({ v[i],cnt });
			cnt++;
			
		}
		tmp = v[i];

	}
	for (int i = 0; i < v2.size(); i++) {
		cout << m[v2[i]] << " ";
	}

	
	return 0;


}