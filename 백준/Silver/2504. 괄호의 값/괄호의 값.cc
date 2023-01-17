#include <iostream>
#include <string>
#include <stack>


using namespace std;
stack<char> stk;
bool error = false;
int result = 0;
int tmp = 1;

int main()
{
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '[')
		{
			stk.push(a[i]);
			tmp *= 3;
		}
		else if (a[i] == '(')
		{
			stk.push(a[i]);
			tmp *= 2;
		}
		else if (a[i] == ']')
		{
			if (stk.empty() || stk.top() == '(')
			{
				error = true;
				break;
			}
			else
			{
				if (a[i - 1] == '[')
					result += tmp;
				tmp /= 3;
				stk.pop();
			}
		}
		else if (a[i] == ')')
		{
			if (stk.empty() || stk.top() == '[')
			{
				error = true;
				break;
			}
			else
			{
				if (a[i - 1] == '(')
					result += tmp;
				tmp /= 2;
				stk.pop();
			}
		}
	}
	if (error == true || !stk.empty())
		cout << 0;
	else
		cout << result;
	return 0;
}