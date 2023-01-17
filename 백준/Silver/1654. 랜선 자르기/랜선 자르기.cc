#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> v;
int n;
int ans = 0;
void binarysearch(long long s, long long e)
{
	if (s>e)
		return;
	long long num = (e + s) / 2;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		cnt += v[i] / num;
	}
	
	if (cnt < n)
		return binarysearch(s, num-1);
	else
	{
		if (ans < num)
			ans = num;
		return binarysearch(num + 1, e);
	}
}

int main()
{
	int k;
	cin >> k >> n;
	long long big = 0;
	
	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
		if (num > big)
			big = num;
	}
	binarysearch(1, big);
	cout << ans;
	


	return 0;
}