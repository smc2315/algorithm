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
	int mmax = 0;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
		if (n > mmax)
			mmax = n;
	}
	long long result = -1;
	long long begin =0;
	long long end = mmax;
	while (begin <= end)
	{
		long long mid = (begin + end) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			if (v[i] - mid > 0)
				sum += v[i] - mid;
		}
		if (sum == M)
		{
			result = mid;
			break;
		}
		else if (sum > M)
		{
			begin = mid + 1;
		}
		else
			end = mid - 1;
	}
	if (result == -1)
	{
		long long sum = 0;
		for (int i = 0; i < N; i++)
			sum += v[i]-begin;
		if (sum < M)
			cout << begin - 1;
		else
			cout << begin + 1;
	}
	else
	{
		cout << result;
	}
	return 0;
}