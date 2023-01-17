#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string result ="";
	stack<int> stk;
	int n;
	cin >> n;
	int i = 1;
	int cnt = 1;
	bool no = false;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k >= cnt)
		{
			while (cnt <= k)
			{
				stk.push(cnt++);
				result += "+\n";
			}
			stk.pop();
			result += "-\n";

		}
		else
		{
			if (stk.top() == k)
			{
				stk.pop();
				result += "-\n";

			}
			else
			{
				cout << "NO";
				no = true;
				break;
			}
		}
	}
	if (no == false)
		cout << result;
	

	return 0;
}