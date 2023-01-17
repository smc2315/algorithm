#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int k = i;
		int sum = 0;
		while (k > 0)
		{
			sum += (k % 10);
			k /= 10;
		}
		if ((sum+i) == n)
		{
			result = i;
			break;
		}
	}
	cout << result;
	return 0;
}