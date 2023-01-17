#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	queue<int> q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);
	int cnt = 1;
	int result;
	while (!q.empty())
	{
		int tmp;
		result = q.front();
		if (cnt % 2 != 0)
		{
			q.pop();
		}
		else
		{
			tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		cnt++;
	}
	cout << result;
	return 0;
}