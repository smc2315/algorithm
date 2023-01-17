#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		stack<char> stk;
		string s;
		cin >> s;
		bool answer = false;
		for (int j = 0; j < s.length(); j++)
		{
			char c;
			c = s[j];
			if (c == '(')
				stk.push('(');
			else if (c == ')')
			{
				if (stk.empty())
				{
					cout << "NO" << endl;
					answer = true;
					break;
				}
				else if (stk.top() == '(')
					stk.pop();
			}

		}
		if (answer == false)
		{
			if (stk.empty())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}