#include <iostream>
#include <utility>
#include <vector>
#include <deque>

using namespace std;
typedef pair<int,int> p;
deque<p> dq;
int n;
int ans = 0;


int main()
{
	int n;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		v.push_back(m);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int k;
		cin >> k;
		dq.clear();
		dq.push_back({0, 0 });
		for (int j = 1; j < n; j++)
		{
			while (!dq.empty() && dq.front().first + k < j)
				dq.pop_front();
			p cur;
			if (v[dq.front().first] <= v[j])
				cur = { j,dq.front().second + 1 };
			else
				cur = { j, dq.front().second };
			while (!dq.empty() && dq.back().second >= cur.second)
			{
				if (dq.back().second > cur.second)
				{
					dq.pop_back();
				}
				else
				{
					if (v[dq.back().first] <= v[j])
						dq.pop_back();
					else break;
				}
			}
			if (j == n - 1)
				cout << cur.second << endl;
			dq.push_back(cur);
		}
	}
	


	return 0;
}