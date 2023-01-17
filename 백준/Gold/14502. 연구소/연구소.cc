#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int graph[9][9];
int n, m;
int ones = 0;
vector<pair<int, int>> v;
vector<pair<int, int>> zeros;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int ans = 0;
void bfs() {
    bool visited[9][9]={0,};
    int cnt = 0;
    for (int i = 0;i < v.size();i++) {
        queue<pair<int, int>> q;
        if (!visited[v[i].first][v[i].second]) {
            q.push(v[i]);
            cnt++;
            visited[v[i].first][v[i].second] = true;

            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                if (cnt == n * m - ones - 3)
                    return;

                for (int j = 0;j < 4;j++) {
                    int nextX = cur.first + dx[j];
                    int nextY = cur.second + dy[j];
                    if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < m && graph[nextX][nextY] != 1 && !visited[nextX][nextY]) {
                        q.push({ nextX,nextY });
                        visited[nextX][nextY] = true;
                        cnt++;
                    }
                }

            }

        }
    }

    if (ans < n * m - ones - 3 - cnt) {
        ans = n * m - ones - 3 - cnt;
    }
}

void select(int num, int s ) {
    if (num == 3) {
        
        bfs();
        return;
    }
    if (s >= zeros.size()) {
        return;
    }
    auto cur = zeros[s];
    select(num, s + 1);
    graph[cur.first][cur.second] = 1;
    select(num + 1, s + 1);
    graph[cur.first][cur.second] = 0;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            int k;
            cin >> k;
            if (k == 1)
                ones++;
            else if(k == 2) {
                v.push_back({ i,j });
            }
            else {
                zeros.push_back({ i,j });
            }
           graph[i][j]=k;
        }
    }
    select(0,0);
    cout << ans;
    return 0;
}