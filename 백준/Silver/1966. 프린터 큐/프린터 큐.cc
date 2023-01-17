#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int k, l;
	
	for (int i = 0; i < n; i++)
	{
		priority_queue<int> q;
		queue<pair<int, int>> q2;
		cin >> k >> l;
		for (int j = 0; j < k; j++)
		{
			pair<int,int> p;
			cin >> p.first;
			p.second = j;
			q.push(p.first);
			q2.push(p);
		}
		int cnt = 1;
		pair<int, int> tmp;
		while(!q2.empty())
		{
			if (q2.front().first == q.top())
			{
				
				if (q2.front().second == l)
				{
					cout << cnt << endl;
					break;
				}
				q2.pop();
				q.pop();
				cnt++;
			}
			else
			{
				tmp = q2.front();
				q2.pop();
				q2.push(tmp);
			}
			
		}

	}
	
	
	return 0;
}