#include <iostream>
#include <queue>
#include<vector>
#include<algorithm>
using namespace std;

int R, C, T;
int graph[50][50];
vector<pair<int,int>> airFresher;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dust() {
	int tmp[50][50] = { 0, };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] > 0) {
				int num = graph[i][j] / 5;
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (x >=0 && x < R && y>=0 && y < C) {
						if (make_pair(x,y) != airFresher[0] && make_pair(x, y) != airFresher[1]) {
							tmp[x][y] += num;
							cnt++;
						}
					}
					
				}
				tmp[i][j] += graph[i][j] - cnt * num;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			graph[i][j] = tmp[i][j];
		}
	}
}
void wind() {
	for (int i = airFresher[0].first-1; i >0; i--) {
		graph[i][0] = graph[i - 1][0];
	}
	for (int i = 0; i < C-1; i++) {
		graph[0][i] = graph[0][i + 1];
	}
	for (int i = 0; i < airFresher[0].first ; i++) {
		graph[i][C - 1] = graph[i + 1][C - 1];
	}
	
	for (int i = C - 1; i > 0; i--) {

		graph[airFresher[0].first][i] = graph[airFresher[0].first][i - 1];
	}


	for (int i = airFresher[1].first+1; i < R-1; i++) {
		graph[i][0] = graph[i + 1][0];
	}
	for (int i = 0; i < C - 1; i++) {
		graph[R-1][i] = graph[R-1][i + 1];
	}
	for (int i = R; i > airFresher[1].first; i--) {
		graph[i][C - 1] = graph[i - 1][C - 1];
	}

	for (int i = C - 1; i > 0; i--) {

		graph[airFresher[1].first][i] = graph[airFresher[1].first][i - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == -1) {
				airFresher.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < T; i++) {
		dust();
		wind();
	}
	
	
	int result = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] > 0) {
				result += graph[i][j];
			}
		}
		
	}
	cout << result<<endl;
	

	return 0;
}