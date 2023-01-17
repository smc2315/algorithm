#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int v[10001] = { 0, };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		v[k]++;
	}
	for (int i = 0; i < 10001; i++)
	{
		if (v[i] != 0)
			for (int j = 0; j < v[i]; j++)
				cout << i << "\n";
	}
	return 0;
}