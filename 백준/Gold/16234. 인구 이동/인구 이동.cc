#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int n, l, r;
int graph[51][51];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

bool bfs() {
    bool visited[51][51];
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            visited[i][j] = false;
        }
    }
    bool check = false;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (!visited[i][j]) {
                vector<pair<int, int>> v;
                int ssum = 0;
                pair<int, int> s = { i,j };
                visited[s.first][s.second] = true;
                queue<pair<int, int>> q;
                q.push(s);
                v.push_back(s);
                ssum += graph[s.first][s.second];
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    for (int k = 0;k < 4;k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && abs(graph[cur.first][cur.second] - graph[nx][ny]) >= l && abs(graph[cur.first][cur.second] - graph[nx][ny]) <= r) {
                            visited[nx][ny] = true;
                            check = true;
                            q.push({ nx,ny });
                            v.push_back({ nx,ny });
                            ssum += graph[nx][ny];
                        }
                    }
                }
                for (int k = 0;k < v.size();k++) {
                    graph[v[k].first][v[k].second] = ssum / v.size();
                }
            }
        }

    }
    
    return check;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> graph[i][j];
        }
    }
    bool check = true;
    int cnt = 0;
    while (true) {
        check = bfs();
        if (!check) {
            cout<<cnt;
            return 0;
        }
        cnt++;
    }
    return 0;
}