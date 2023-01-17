#include <iostream>
#include <string>
#include<vector>
#include<queue>
#include<math.h>
#include<cstring>
using namespace std;
int n,k;
int graph[101][101];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int dir;

int time = 0;

vector<pair<int, char>> v;
deque<pair<int, int>> q;

void go(int idx) {
	while (true) {
		
		if (idx<v.size()&&time == v[idx].first) {
			
			if (v[idx].second == 'L') {
				dir = (dir + 1) % 4;
			}
			else {
				dir = (dir +3) % 4;
			}
			idx++;

		}
		int hx = q.front().first;
		int hy = q.front().second;

		int nx = hx + dx[dir];
		int ny = hy + dy[dir];
		if (graph[nx][ny] == 1) {
			graph[nx][ny] = 2;
			q.push_front({ nx,ny });
		}
		else if (nx >= 0 && ny >= 0 && nx < n&&ny < n&&graph[nx][ny] != 2) {
			graph[nx][ny] = 2;
			q.push_front({ nx,ny });
			int tx = q.back().first;
			int ty = q.back().second;
			graph[tx][ty] = 0;
			q.pop_back();

			
		}
		else {
			cout << time+1;
			exit(0);
		}
		
		time++;
		
	}
	
	return;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n>>k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		graph[x-1][y-1] = 1;
	}
	graph[0][0] = 2;
	q.push_front({ 0,0 });
	dir = 3;
	int L;
	cin >> L;
	for (int i = 0; i < L; i++) {
		int  X;
		char C;
		cin >> X >> C;
		v.push_back({ X,C });
	}
	go(0);
	
	
	return 0;
}