#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int arr[51][51];
vector<pair<int, int>> virus;
int cnt_wall;
bool selected[51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int answer = 1e9;

int cal_time() {
	int ret = -1;
	bool visited[51][51];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		if (selected[i]) {
			
			q.push(virus[i]);
			visited[virus[i].first][virus[i].second] = true;
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int tmp = q.size();
		while (tmp--) {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx >= 0 && ny >= 0 && nx < N && ny < N && arr[nx][ny] != 1 && !visited[nx][ny]) {
					q.push({ nx,ny });
					visited[nx][ny] = true;
					cnt++;
				}
			}
		}
		ret++;
	}
	
	if (N * N - cnt_wall - M == cnt)
		return ret;
	else
		return 1e9;
}

void back_track(int n,int s) {
	if (n == M) {
	
		int t = cal_time();
		answer = min(answer, t);
		return;
	}
	for (int i = s; i < virus.size(); i++) {
		selected[i] = true;
		back_track(n + 1, i + 1);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				virus.push_back({ i,j });
				
			}
			else if (arr[i][j] == 1) {
				cnt_wall++;
			}
		}
	}
	back_track(0, 0);
	if (answer == 1e9) {
		cout << -1;
		return 0;
	}
	cout << answer;

	return 0;
}