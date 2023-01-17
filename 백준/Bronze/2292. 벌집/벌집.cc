#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	if (n == 1)
		cout << 1;
	else
	{
		int k = 2;
		for (int i = 0; i < 100000; i++)
		{
			k += i * 6;
			if (n >= k && n<=k+5+(i*6))
			{
				cout << i + 2;
				break;
			}
		}
	}
	return 0;
}