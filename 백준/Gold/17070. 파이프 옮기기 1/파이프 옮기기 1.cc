#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int graph[16][16];
int visited[16][16];

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,1},0 });
	visited[0][1]++;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int rot = q.front().second;
		//cout << "x= " << x << "y= " << y <<" " <<visited[x][y]<< endl;
		q.pop();
		if (rot == 0) {
			if (y+1<n&&graph[x][y+1] != 1) {
				q.push({ {x,y+1},0 });
				visited[x][y+1]++;
			}
			if (x+1<n&&y+1<n&&graph[x + 1][y + 1] != 1 && graph[x + 1][y] != 1 && graph[x][y + 1] != 1) {
				q.push({ {x + 1,y + 1},2 });
				visited[x + 1][y + 1]++;
			}
		}
		else if (rot == 1) {
			if (x+1<n&&graph[x+1][y] != 1) {
				q.push({ {x+1,y},1 });
				visited[x+1][y]++;
			}
			if (x+1<n&&y+1<n&&graph[x + 1][y + 1] != 1 && graph[x + 1][y] != 1 && graph[x][y + 1] != 1) {
				q.push({ {x + 1,y + 1},2 });
				visited[x + 1][y + 1]++;
			}
		}
		else {
			if (x + 1 < n && graph[x + 1][y] != 1) {
				q.push({ {x + 1,y},1 });
				visited[x + 1][y]++;
			}
			if (y + 1 < n && graph[x][y + 1] != 1) {
				q.push({ {x,y + 1},0 });
				visited[x][y + 1]++;
			}
			if (x + 1 < n && y + 1 < n && graph[x + 1][y + 1] != 1 && graph[x + 1][y] != 1 && graph[x][y + 1] != 1) {
				q.push({ {x + 1,y + 1},2 });
				visited[x + 1][y + 1]++;
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}

	}

	bfs();
	cout << visited[n-1][n-1];
	
	

	return 0;
}