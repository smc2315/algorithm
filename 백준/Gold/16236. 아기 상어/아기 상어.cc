#include <iostream>
#include <string>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
using namespace std;

int n;
int ssize = 2;
int graph[21][21];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int time = 0;
pair<pair<int, int>, int> findFish(int x, int y) {

	queue<pair<pair<int, int>, int>> q;
	bool visited[21][21];
	memset(visited, false, sizeof(visited));
	pair<pair<int, int>, int> p = { { 21,21 },-1 };
	q.push({ { x, y },0 });
	visited[x][y] = true;
	int dist = 100000;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		
		if (dist < cur.second) {

			return p;
		}
		if (graph[cur.first.first][cur.first.second] != 0 && graph[cur.first.first][cur.first.second] < ssize) {
			if (dist == 100000) {
				dist = cur.second;
				p = cur;
			}
			else if (dist == cur.second) {
				if (p.first.first > cur.first.first) {
					p = cur;
				}
				else if (p.first.first == cur.first.first) {
					if (p.first.second > cur.first.second) {
						p = cur;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.first.first + dx[i];
			int ny = cur.first.second + dy[i];
			

			if (nx >= 0 && ny >= 0 && nx < n&&ny < n && graph[nx][ny] <= ssize && !visited[nx][ny]) {
				q.push({ { nx,ny }, cur.second + 1 });
				visited[nx][ny] = true;
			}
		}
	}
	return p;
}

void go(int cnt, int x, int y) {

	if (cnt == ssize) {
		ssize++;
		cnt = 0;
	}
	
	auto fish = findFish(x, y);
	if (fish.second == -1)
		return;
	else {
		graph[x][y] = 0;
		graph[fish.first.first][fish.first.second] = 0;
		time += fish.second;
		go(cnt + 1, fish.first.first, fish.first.second);

	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 9) {
				x = i; y = j;
			}
			else if (tmp != 0) {

			}
			graph[i][j] = tmp;
		}
	}
	go(0, x, y);
	cout << time;
	return 0;
}