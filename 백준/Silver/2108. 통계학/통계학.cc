#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sansul = 0;
	vector<int> cen;
	int sig[8001] = { 0, };
	int big = -4001;
	int small = 4001;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		sansul += m;
		cen.push_back(m);
		sig[4000 + m]++;
		if (m < small)
			small = m;
		if (m > big)
			big = m;
	}
	sort(cen.begin(), cen.end());
	vector<int> cnt;;
	int real = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (real < sig[i])
		{
			vector<int>().swap(cnt);
			real = sig[i];
			cnt.push_back(i);
		}
		else if (real == sig[i])
			cnt.push_back(i);
	}
	int mostsig = 0;
	if (cnt.size() == 1)
		mostsig = cnt[0];
	else
		mostsig = cnt[1];

	cout << floor((float)sansul / n + 0.5) << endl << cen[n / 2] << endl << mostsig-4000 << endl << big - small;
	
	
	return 0;
}