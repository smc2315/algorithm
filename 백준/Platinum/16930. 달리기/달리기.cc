#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;


int N, M, K;
char map[1001][1001];
int visited[1001][1001];
int x, y, x2, y2;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
void bfs() {
	queue<pair<int,int>> q;
	q.push({ x,y });
	visited[x][y] = 0;
	while (!q.empty()) {
		auto cur = q.front();
		
	
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int cx = cur.first;
			int cy = cur.second;
			for (int j = 0; j <	K; j++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx >= 0 && ny >= 0 && nx < N&&ny < M && map[nx][ny] != '#' && visited[nx][ny] >=visited[cur.first][cur.second]+1) {
					if (visited[nx][ny] == (int)1e9){
						visited[nx][ny] = visited[cur.first][cur.second] + 1;
						q.push({ nx,ny });
					}
					cx = nx;
					cy = ny;
				}
				else
					break;
			}
		}
	}
	visited[x2][y2] == 1e9 ? cout << -1 : cout << visited[x2][y2];
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			map[i][j]=tmp[j];
			visited[i][j] = 1e9;
		}
	}
	cin >> x >> y >> x2 >> y2;
	x--; y--; x2--; y2--;
	bfs();
	
	return 0;
}