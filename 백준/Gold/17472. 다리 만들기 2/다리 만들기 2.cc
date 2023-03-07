#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N, M, ans;
int map[11][11];
bool visited[11][11];
int index_ = 1;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<tuple<int, int, int>> edge;
vector<pair<int, int>> island[7];


int parent[7];
bool in_range(int x, int y) {
	return (x >= 0 && y >= 0 && x < N&&y < M);
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

		}
	}
}
void set_parent() {
	for (int i = 1; i < 7; i++) {
		parent[i] = i;
	}
}
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}
bool same_parent(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	return false;
}

void set_island() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visited[i][j] = true;
				map[i][j] = index_;
				island[index_].push_back({ i,j });
				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.first + dx[k];
						int ny = cur.second + dy[k];
						if (in_range(nx, ny) && !visited[nx][ny] && map[nx][ny]) {
							q.push({ nx,ny });
							visited[nx][ny] = true;
							map[nx][ny] = index_;
							island[index_].push_back({ nx,ny });
						}
					}
				}
				index_++;
			}
		}
	}
}
void get_edges() {
	for (int i = 1; i < index_; i++) {
		vector<int> v(index_ - i);
		for (int j = 0; j < v.size(); j++) {
			v[j] = 1e9;
		}
		for (int j = 0; j < island[i].size(); j++) {
			auto cur = island[i][j];
			for (int k = 0; k < 4; k++) {
				int nx = cur.first + dx[k];
				int ny = cur.second + dy[k];
				int cnt = 0;

				while (in_range(nx, ny) && map[nx][ny] != i) {
					if (map[nx][ny] > i) {
						if (cnt > 1) {
							v[map[nx][ny] - i] = min(v[map[nx][ny] - i], cnt);
						}
						break;
					}
					else if (map[nx][ny] != 0)
						break;
					nx += dx[k];
					ny += dy[k];
					cnt++;
				}
			}
		}
		for (int j = 1; j < v.size(); j++) {
			if (v[j] < 1e9) {
				
				edge.push_back({ v[j],i,j + i });
			}
		}
	}

}
void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

}
void kruskal() {
	set_parent();
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++) {
		if (!same_parent(get<1>(edge[i]), get<2>(edge[i]))) {
			uni(get<1>(edge[i]), get<2>(edge[i]));
			ans += get<0>(edge[i]);
			
		}
	}
	
	for (int i = 1; i < index_; i++) {
		if (find(i) != 1) {
			cout << -1;
			return;
		}
	}
	cout << ans;
}
void solve() {
	input();
	set_island();
	//print();
	get_edges();
	/*for (int i = 0; i < edge.size(); i++) {
		cout << get<1>(edge[i]) << " " << get<2>(edge[i]) << " " << get<0>(edge[i]) << endl;
	}*/
	kruskal();
	
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}