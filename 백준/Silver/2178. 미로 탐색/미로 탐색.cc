#include <iostream>
#include <string>
#include <queue>
using namespace std;
int map[101][101] ;
bool visited[101][101];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int bfs(int x,int y,int n,int m)
{
	int cnt = 1;
	for (int i = 0; i < 4; i++)
	{
		queue<pair<pair<int, int>, int>> q;
		q.push({{ x, y }, cnt});
		visited[x][y] = true;
		while (!q.empty())
		{
			int xx = q.front().first.first;
			int yy = q.front().first.second;
			cnt = q.front().second;
			if (n - 1 == xx && m - 1 == yy)
				return cnt;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int dxx = xx + dx[i];
				int dyy = yy + dy[i];
				
				if (dxx >= 0 && dxx < 101 && dyy >= 0 && dyy < 101 )
				{
					if (map[dxx][dyy] == 1 && visited[dxx][dyy] == false)
					{
						q.push({{ dxx,dyy }, cnt+1});
						visited[dxx][dyy] = true;
					
					}
				}

			}
		}
		

	}
}

int main() 
{
	int n,m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}
	int cnt =bfs(0,0,n,m);
	cout << cnt;
	
	return 0;
}