#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int ans = 0;
int num = 0;
string dir = "rlud";

int getMax(vector<vector<int>> graph) {
	int mmax = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mmax < graph[i][j])
				mmax = graph[i][j];
		}
	}
	return mmax;
}

vector<vector<int>> right(vector<vector<int>> v) {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (v[i][j] == 0) {
				for (int k = j; k >= 1; k--) {
					v[i][k] =v[i][k - 1];
				}
				v[i][0] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int  tmp = v[i][n - 1];
		for (int j = n - 2; j >= 0; j--) {
			if (v[i][j] == tmp) {
				v[i][j + 1] *= 2;
				for (int k = j; k >= 1; k--) {
					v[i][k] =v[i][k - 1];
				}
				v[i][0] = 0;
				tmp = v[i][j];

			}
			else {
				tmp = v[i][j];
			}
		}
	}
	return v;
}

vector<vector<int>> left(vector<vector<int>> v) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 2; j >= 0; j--) {
			if (v[i][j] == 0) {
				for (int k = j; k < n - 1; k++) {
					v[i][k] = v[i][k + 1];
				}
				v[i][n - 1] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int  tmp = v[i][0];
		for (int j = 1; j < n; j++) {
			if (v[i][j] == tmp) {
				v[i][j - 1] *= 2;
				for (int k = j; k < n - 1; k++) {
					v[i][k] = v[i][k + 1];
				}
				v[i][n - 1] = 0;
				tmp = v[i][j];

			}
			else {
				tmp = v[i][j];
			}
		}
	}
	return v;
}

vector<vector<int>> up(vector<vector<int>> v) {

	for (int j = 0; j < n; j++) {
		for (int i = n - 2; i >= 0; i--) {
			if (v[i][j] == 0) {
				for (int k = i; k < n - 1; k++) {
					v[k][j] = v[k + 1][j];
				}
				v[n - 1][j] = 0;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		int  tmp = v[0][j];
		for (int i = 1; i < n; i++) {
			if (v[i][j] == tmp) {
				v[i - 1][j] *= 2;
				for (int k = i; k < n - 1; k++) {
					v[k][j] = v[k + 1][j];
				}
				v[n - 1][j] = 0;
				tmp = v[i][j];

			}
			else {
				tmp = v[i][j];
			}
		}
	}
	return v;
}

vector<vector<int>> down(vector<vector<int>> v) {

	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			if (v[i][j] == 0) {
				for (int k = i; k >= 1; k--) {
					v[k][j] = v[k - 1][j];
				}
				v[0][j] = 0;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		int  tmp = v[n - 1][j];
		for (int i = n - 2; i >= 0; i--) {
			if (v[i][j] == tmp) {
				v[i + 1][j] *= 2;
				for (int k = i; k >= 1; k--) {
					v[k][j] = v[k - 1][j];
				}
				v[0][j] = 0;
				tmp = v[i][j];

			}
			else {
				tmp = v[i][j];
			}
		}
	}
	return v;
}
void move(int cnt,vector<vector<int>> v) {
	int tmp = getMax(v);
	if (ans < tmp) {
		ans = tmp;

	}
	if (cnt == 5) {
		
		
		return;
	}
	move(cnt + 1, right(v));
	move(cnt + 1, left(v));
	move(cnt + 1, up(v));
	move(cnt + 1, down(v));
	
	

	

	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	move(0,graph);
	cout << ans;



	return 0;
}