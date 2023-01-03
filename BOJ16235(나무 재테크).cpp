#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include <stack>

using namespace std;
int N,M,K;
int ground[11][11];
int nutrient[11][11];
int grow[11][11];
vector<vector<deque<int>>> tree(11, vector<deque<int>>(11, deque<int>()));

void input() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			
			ground[i][j] = 5;
			cin >> nutrient[i][j];
		}
			
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x-1][y-1].push_back(z);
	}
}

void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			int cnt = 0;
			for(int k=0;k<tree[i][j].size();k++){

				if (tree[i][j][k] <= ground[i][j]) {
					
					ground[i][j] -= tree[i][j][k];
					tree[i][j][k] += 1;
					if (tree[i][j][k] % 5 == 0) {
						grow[i][j]++;
					}
				}
				else {
					int tmp = tree[i][j].size();
					while (k<tmp) {
						cnt+=tree[i][j].back() / 2;
						tree[i][j].pop_back();
						k++;
					}
				}
				
			}
			
			ground[i][j] += cnt;
		}
	}
}

void autumn() {
	int dx[8] = { -1,-1,-1,0,0,1,1,1};
	int dy[8] = { -1,0,1,-1,1,-1,0,1 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			while (grow[i][j]) {
				for (int k = 0; k < 8; k++) {
					if (i + dx[k] >= 0 && i + dx[k] < N&&j + dy[k] >= 0 && j + dy[k] < N) {
						tree[i + dx[k]][j + dy[k]].push_front(1);
					}
				}
				grow[i][j]--;
			}
		}
	}
}

void winter() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ground[i][j] += nutrient[i][j];
		}
	}
}
void result() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cnt += tree[i][j].size();
		}
	}
	cout << cnt;
}

void solve() {
	input();
	while (K--) {
		spring();
		autumn();
		winter();
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (auto k : tree[i][j]) {
					cout << k << " ";
				}
				cout << "  ";
			}
			cout << endl;
		}
		cout << "--------------------" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << ground[i][j] << " ";
			}
			cout << endl;
		}*/
		//cout << ground[0][0]<<endl;
	}
	result();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	
	return 0;
}
