#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n,m;
int arr[101][101];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
int ttime, ans;
bool visited[101][101];

bool bfs(){
    memset(visited, false, sizeof(visited));
    visited[0][0] = true;
	int cnt=0;
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	ttime++;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny]) {
				if (arr[nx][ny] == 0) {
					q.push({ nx,ny });
				}
				else {
					arr[nx][ny] = 0;
					cnt++;
				}
				visited[nx][ny] = true;
			}
		}
	}
    if (cnt == 0) {
		cout << ttime-1<<endl<<ans;
		return false;
	}
	else {
		ans = cnt;
		return true;
	}
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    while(bfs()){

    }
}