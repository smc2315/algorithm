#include <iostream>
#include <string>
#include<vector>
#include<queue>

using namespace std;
int n,K;

int graph[13][13];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

vector<pair<pair<int, int>, int>> v;

vector<vector<deque<int>>> state(13,vector<deque<int>>(13));

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (state[i][j].size()>= 4)
				return true;
		}
	}
	return false;
}
void go(int cnt) {
	if (check()) {
		cout << cnt;
		exit(0);
	}
	cnt++;
	
	if (cnt > 1000) {
		cout << -1;
		exit(0);
	}
	for (int i = 0; i < K; i++) {
		if (check()) {
			cout << cnt;
			exit(0);
		}
		auto tmp = v[i];
		auto cur = v[i].first;
		int curD = v[i].second;
		/*for (int j = 0; j < K; j++) {
			cout << v[j].first.first<<" " << v[j].first.second << endl;
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < state[j][k].size(); l++) {
					cout << state[j][k][l];
				}
				cout << " | ";
			}
			cout << endl;
		}
		cout << endl;
		*/
		int nextX = cur.first + dx[curD];
		int nextY = cur.second + dy[curD];

		if (nextX >= 0 && nextY >= 0 && nextX < n&&nextY < n&&graph[nextX][nextY] != 2) {
			if (graph[nextX][nextY] == 0) {
				deque<int> tmpQ;
				while (1) {
					
					int k = state[cur.first][cur.second].front();
					
					if (k == i) {
						while (!state[cur.first][cur.second].empty()) {
							int m = state[cur.first][cur.second].front();
							v[m].first = { nextX,nextY };
							state[nextX][nextY].push_back(m);
							state[cur.first][cur.second].pop_front();
							
							
						}
						
						state[cur.first][cur.second] = tmpQ;
						break;
					}
					state[cur.first][cur.second].pop_front();
					tmpQ.push_back(k);
				}
			}
			else {
				deque<int> tmpQ;
				while (1) {
					
					int k = state[cur.first][cur.second].front();

					if (k == i) {
						while (!state[cur.first][cur.second].empty()) {
							int m = state[cur.first][cur.second].back();
							v[m].first = { nextX,nextY };
							state[nextX][nextY].push_back(m);
							state[cur.first][cur.second].pop_back();

						}
						state[cur.first][cur.second] = tmpQ;
						break;
					}
					state[cur.first][cur.second].pop_front();
					tmpQ.push_back(k);
				}

			}
		}
		else {
			int nextX = cur.first - dx[curD];
			int nextY = cur.second - dy[curD];
			if (v[i].second % 2 == 1) {
				v[i].second --;
			}
			else {
				v[i].second++;
			}
			if (nextX >= 0 && nextY >= 0 && nextX < n&&nextY < n&&graph[nextX][nextY] != 2) {
				if (graph[nextX][nextY] == 0) {
					deque<int> tmpQ;
					while (1) {
						
						int k = state[cur.first][cur.second].front();

						if (k == i) {
							while (!state[cur.first][cur.second].empty()) {
								int m = state[cur.first][cur.second].front();
								v[m].first = { nextX,nextY };
								state[nextX][nextY].push_back(m);
								state[cur.first][cur.second].pop_front();


							}
							state[cur.first][cur.second] = tmpQ;
							break;
						}
						state[cur.first][cur.second].pop_front();
						tmpQ.push_back(k);
					}
				}
				else {
					deque<int> tmpQ;
					while (1) {
						
						int k = state[cur.first][cur.second].front();

						if (k == i) {
							while (!state[cur.first][cur.second].empty()) {
								int m = state[cur.first][cur.second].back();
								v[m].first = { nextX,nextY };
								state[nextX][nextY].push_back(m);
								state[cur.first][cur.second].pop_back();


							}
							state[cur.first][cur.second] = tmpQ;
							break;
						}
						state[cur.first][cur.second].pop_front();
						tmpQ.push_back(k);
					}

				}
			}
			

		}
	}
	go(cnt);

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n>>K;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		v.push_back({ {x - 1,y - 1},d -1 });
		state[x - 1][y - 1].push_back(i);

	}
	go(0);
	
	return 0;
}