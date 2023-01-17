#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> v(20000010);
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d",&k);
		v[k + 10000000]++;
	}
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d",&k);
		printf("%d ",v[k + 10000000]);
	}
	return 0;
}