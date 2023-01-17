#include <iostream>
#include <queue>
#include <vector>
#include <queue>
using namespace std;

int n,m,x,y,k;
int graph[21][21];
deque<int> rl;
deque<int> fb ;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x >> y >> k;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> graph[i][j];
        }
    }
    rl.push_back(0);
    rl.push_back(0);
    rl.push_back(0);
    rl.push_back(0);

    fb.push_back(0);
    fb.push_back(0);
    fb.push_back(0);
    fb.push_back(0);

    for (int i = 0;i < k;i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            int nx = x + dx[tmp - 1];
            int ny = y + dy[tmp - 1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                x = nx;
                y = ny;
                int t = rl.back();
                rl.pop_back();
                rl.push_front(t);
                if (graph[x][y] == 0) {
                    graph[x][y] = rl[2];
                }
                else {
                    rl[2] = graph[x][y];
                    graph[x][y] = 0;
                }
                fb[0] = rl[0];
                fb[2] = rl[2];
                cout << rl[0] << endl;
            }
        }
        else if (tmp == 2) {
            int nx = x + dx[tmp - 1];
            int ny = y + dy[tmp - 1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                x = nx;
                y = ny;
                int t = rl.front();
                rl.pop_front();
                rl.push_back(t);
                if (graph[x][y] == 0) {
                    graph[x][y] = rl[2];
                }
                else {
                    rl[2] = graph[x][y];
                    graph[x][y] = 0;
                }
                fb[0] = rl[0];
                fb[2] = rl[2];
                cout << rl[0] << endl;
            }
        }
        else if (tmp == 3) {
            int nx = x + dx[tmp - 1];
            int ny = y + dy[tmp - 1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                x = nx;
                y = ny;
                int t = fb.front();
                fb.pop_front();
                fb.push_back(t);
                if (graph[x][y] == 0) {
                    graph[x][y] = fb[2];
                }
                else {
                    fb[2] = graph[x][y];
                    graph[x][y] = 0;
                }
                rl[0] = fb[0];
                rl[2] = fb[2];
                cout << rl[0] << endl;
            }
        }
        else {
            int nx = x + dx[tmp - 1];
            int ny = y + dy[tmp - 1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                x = nx;
                y = ny;
                int t = fb.back();
                fb.pop_back();
                fb.push_front(t);
                if (graph[x][y] == 0) {
                    graph[x][y] = fb[2];
                }
                else {
                    fb[2] = graph[x][y];
                    graph[x][y] = 0;
                }
                rl[0] = fb[0];
                rl[2] = fb[2];
                cout << rl[0] << endl;
            }
        }
        
    }

    
    return 0;
}