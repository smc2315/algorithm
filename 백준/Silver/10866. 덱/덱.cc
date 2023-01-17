#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;


int main()
{
	deque<int> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "push_front")
		{
			int k;
			cin >> k;
			q.push_front(k);
		}
		else if (s == "push_back")
		{
			int k;
			cin >> k;
			q.push_back(k);
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
		else if (s == "pop_front")
		{
			if (!q.empty())
			{
				cout << q.front() << endl;
				q.pop_front();
			}
			else
				cout << -1 << endl;
		}
		else if (s == "pop_back")
		{
			if (!q.empty())
			{
				cout << q.back() << endl;
				q.pop_back();
			}
			else
				cout << -1 << endl;
		}
	}
	return 0;
}