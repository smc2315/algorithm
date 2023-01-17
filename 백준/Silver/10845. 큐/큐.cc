#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


int main()
{
	queue<int> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int k;
			cin >> k;
			q.push(k);
		}
		else if (s == "front")
		{
			if (!q.empty())
			{
				cout << q.front() << endl;
			}
			else
				cout << -1 << endl;
		}
		else if (s == "back")
		{
			if (!q.empty())
			{
				cout << q.back() << endl;
			}
			else
				cout << -1 << endl;
		}
		else if (s == "size")
		{
			cout << q.size() << endl;
		}
		else if (s == "empty")
		{
			cout << q.empty() << endl;
		}
		else if (s == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << endl;
				q.pop();
			}
			else
				cout << -1 << endl;
		}
	}
	return 0;
}