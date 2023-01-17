#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;


int main()
{
	stack<int> stk;
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
			stk.push(k);
		}
		else if (s == "top")
		{
			if (!stk.empty())
			{
				cout << stk.top() << endl;
			}
			else
				cout << -1 << endl;
		}
		else if (s == "size")
		{
			cout << stk.size() << endl;
		}
		else if (s == "empty")
		{
			cout << stk.empty() << endl;
		}
		else if (s == "pop")
		{
			if (!stk.empty())
			{
				cout << stk.top() << endl;
				stk.pop();
			}
			else
				cout << -1 << endl;
		}
	}
	return 0;
}