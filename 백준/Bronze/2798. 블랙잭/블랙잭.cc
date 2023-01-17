#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}
	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				if (v[i] + v[j] + v[k] <= M && v[i] + v[j] + v[k] > result)
					result = v[i] + v[j] + v[k];
			}
		}
	}
	cout << result;
	return 0;
}