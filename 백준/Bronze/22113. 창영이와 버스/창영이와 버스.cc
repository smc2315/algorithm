#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;

	int num, k;
	int count = 0;
	int ans = 0;
	vector<int> v;
	cin >> N >> M;
	int graph[100][100];
	while (M--)
	{
		cin >> num;
		v.push_back(num);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> graph[i][j];
		}
	}
	k = size(v) - 1;
	while (k)
	{
		ans += graph[v[count]-1][v[++count]-1];
		k--;
	}
	cout << ans << endl;


}