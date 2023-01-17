#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[51][51] = { 0, };
int visited[51][51] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1, 0,-1,0 };
int m, n;
void dfs(int x, int y)
{
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= m || yy < 0 || yy >= n)
			continue;
		if (arr[xx][yy] && !visited[xx][yy])
			dfs(xx, yy);
	}
}


int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int  k;
		int ans = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < m; j++)
		{
			for (int l = 0; l < n; l++)
			{
				arr[j][l] = 0;
				visited[j][l] = 0;
			}
			
		}
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			arr[x][y] = 1;

		}
		
		for (int j = 0; j < m; j++)
		{
			for (int l = 0; l < n; l++)
			{
				if (arr[j][l] ==1 && visited[j][l] == 0)
				{
					
					
					dfs(j, l);
					ans++;

				}
				
				
			}

		}
		cout << ans << endl;
		

	}
	return 0;
}