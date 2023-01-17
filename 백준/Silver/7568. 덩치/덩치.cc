#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	vector<pair<int,int>> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		pair<int,int> p;
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	for (int i = 0; i < v.size(); i++)
	{
		int cnt = 1;
		for (int j = 0; j < v.size(); j++)
		{
			if (i != j)
			{
				if ((v[j].first > v[i].first&&v[j].second > v[i].second))
				{
					cnt++;
				}
			}

		}
		cout << cnt << " ";
	}
	return 0;
}