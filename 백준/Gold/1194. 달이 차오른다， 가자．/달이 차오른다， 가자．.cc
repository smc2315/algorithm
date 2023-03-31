#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int sx, sy;
char arr[51][51];
bool visited[51][51][1<<6];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

typedef struct Node{
	int x;
	int y;
	int keys = 1 << 6;
	int cnt;
};

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '0') {
				sx = i; sy = j;
			}
		}
	}
	
}

bool in_range(int x, int y) {
	return (x >= 0 && y >= 0 && x < N&&y < M);
}


int bfs() {
	queue<Node> q;
	Node n;
	n.x = sx; n.y = sy; n.cnt = 0;
	q.push(n);
	
	
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		if (arr[cur.x][cur.y] == '1') {
			return cur.cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (in_range(nx, ny) && !visited[nx][ny][cur.keys] && arr[nx][ny]!='#') {
				char c = arr[nx][ny];
				int bit = cur.keys;
				switch (c) {
					case 'a': {
						bit |= 1 << 0;
						break;
					}
					case 'b': {
						bit |= 1 << 1;
						break;
					}
					case 'c': {
						bit |= 1 << 2;
						break;
					}
					case 'd': {
						bit |= 1 << 3;
						break;
					}
					case 'e': {
						bit |= 1 << 4;
						break;
					}
					case 'f': {
						bit |= 1 << 5;
						break;
					}
				}

				bool flag = true;
				switch (c) {
				case 'A': {
					if ((bit & 1 << 0) != (1 << 0)) {
						flag = false;
					}
					break;
				}
				case 'B': {
					if ((bit & 1 << 1) != (1 << 1)) {
						flag = false;
					}
					break;
				}
				case 'C': {
					if ((bit & 1 << 2) != (1 << 2)) {
						flag = false;
					}
					break;
				}
				case 'D': {
					if ((bit & 1 << 3) != (1 << 3)) {
						flag = false;
					}
					break;
				}
				case 'E': {
					if ((bit & 1 << 4) != (1 << 4)) {
						flag = false;
					}
					break;
				}
				case 'F': {
					if ((bit & 1 << 5) != (1 << 5)) {
						
						flag = false;
					}
					break;
				}
				}
				if (flag) {
					Node newn;
					newn.x = nx;
					newn.y = ny;
					newn.keys = bit;
					newn.cnt = cur.cnt + 1;
					q.push(newn);
					visited[nx][ny][bit] = true;
				}
			}
		}
	}
	return -1;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	cout << bfs();
	

	
}