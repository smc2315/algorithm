#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{
	while (true)
	{
		bool no = false;
		stack<int> stk;
		string s;
		getline(cin, s);
		if (s == ".")
			break;
		int i = 0;
		while (s[i] != '.')
		{

			if (s[i] == '.')
			{
				break;
			}
			if (s[i] == '(')
				stk.push(s[i]);
			else if (s[i] == '[')
				stk.push(s[i]);
			else if (s[i] == ')' && !stk.empty())
			{
				if (stk.top() == '(')
					stk.pop();
				else
				{
					no = true;
					break;
				}
			}
			else if (s[i] == ')' && stk.empty())
			{
				cout << "no" << endl;
				no = true;
				break;
			}
			else if (s[i] == ']'&&!stk.empty())
			{
				if (stk.top() == '[')
					stk.pop();
				else
				{
					no = true;
					break;
				}
			}
			else if (s[i] == ']' && stk.empty())
			{
				cout << "no" << endl;
				no = true;
				break;
			}
			i++;

		}
		if (!stk.empty())
		{
			cout << "no" << endl;
			while (!stk.empty())
				stk.pop();
		}
		else if(no == false)
			cout << "yes" << endl;
	}
	return 0;
}