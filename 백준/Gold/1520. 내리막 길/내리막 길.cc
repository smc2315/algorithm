#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int arr[501][501];
int dp[501][501];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int dfs(int x,int y) {
    if (x == N - 1 && y == M - 1) 
        return 1;

    int& ret = dp[x][y];

    if (ret != -1) 
        return ret;

    ret = 0;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < N && ny < M){
            if (arr[nx][ny] < arr[x][y]){
                ret += dfs(nx, ny);
            }
        }
    }
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);
	return 0;
}