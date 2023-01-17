#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
	bool arr[1000001];
	int n, m;
	cin >> n >> m;

	arr[1] = true;
	for (int i = 2; i <= sqrt(m); i++)
	{
		
		
		for (int j = 2; i*j <= m; j++)
		{
			arr[i*j] = true;
		}
	}
	for (int i = n; i <= m; i++)
	{
		if (arr[i] != true)
			cout << i << "\n";
	}
	return 0;
}