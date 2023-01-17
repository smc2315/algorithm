#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int apt[15][14];
	for (int i = 0; i < 14; i++)
		apt[0][i] = i + 1;
	for (int i = 1; i < 15; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			int sum = 0;
			for (int k = 0; k < j+1; k++)
			{
				sum += apt[i - 1][k];
			}
			apt[i][j] = sum;
		}
	}
	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		cout << apt[n][k-1] << endl;
	}
	return 0;
}