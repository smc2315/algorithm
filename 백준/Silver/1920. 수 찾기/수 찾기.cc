#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int arr[100001];
int n;
void binarysearch(int num)
{
	int start = 0;
	int end = n-1;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == num)
		{
			cout << 1 << "\n";
			return;
		}
		else if (arr[mid] < num)
			start = mid + 1;
		else
			end = mid - 1;
	}
	cout << 0 << "\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		arr[i] = k;
	}
	sort(arr, arr + n);
    int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >>k;
		binarysearch(k);
	}
	return 0;
}