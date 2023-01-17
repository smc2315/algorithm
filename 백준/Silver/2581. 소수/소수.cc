#include <iostream>

using namespace std;
int main()
{
	int a, b;
	int sum = 0;
	int count;
	int first = 100001;
	cin >> a >> b;
	for (int i = a; i <=b; i++)
	{
		count = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i%j == 0)
				count++;
		}
		if (count == 2 && i<first)
		{
			first = i;
		}
		if (count == 2)
			sum += i;
	}

	if (sum != 0)
		cout << sum << endl << first;
	else
		cout << -1;
	return 0;
}