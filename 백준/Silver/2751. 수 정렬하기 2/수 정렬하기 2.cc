#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";
	return 0;
}