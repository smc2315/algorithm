#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int n,q;
int nn;
int graph[65][65];
bool visited[65][65];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int mmax = 0;
int ssum = 0;

void rotate(int l) {
    int ll = pow(2, l);
    for (int i = 0;i < nn;i+=ll) {
        for (int j = 0;j < nn;j += ll) {
            vector<vector<int>> v(ll, vector<int>(ll));
            int index = 0;
            for (int k = i + ll - 1;k >= i;k--) {
                for (int h = j;h < j + ll;h++) {
                    v[index][h-j]=graph[k][h];
                    
                }
                index++;
            }
            
            for (int h = j;h < j + ll;h++) {
                for (int k = i;k < i + ll;k++) {
                    graph[k][h] = v[h-j][k-i];
                }
            }
        }

    }
}
void reduceIce() {
    vector<pair<int, int>> v;
    for (int i = 0;i < nn;i++) {
        for (int j = 0;j < nn;j++) {
            int cnt = 0;
            if(graph[i][j]!=0){
            for (int k = 0;k < 4;k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && ny >= 0 && nx < nn && ny < nn) {
                    if (graph[nx][ny] > 0)
                        cnt++;
                }
            }
            if (cnt < 3) {
                v.push_back({ i,j });
            }
            }
        }

    }
    for (int i = 0;i < v.size();i++) {
        graph[v[i].first][v[i].second]--;
    }
}

void findLump() {
    for (int i = 0;i < nn;i++) {
        for (int j = 0;j < nn;j++) {
            ssum += graph[i][j];
            if (!visited[i][j]&&graph[i][j]!=0) {
                queue<pair<int, int>> q;
                q.push({ i,j });
                visited[i][j] = true;
                int cnt = 1;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();
                    for (int k = 0;k < 4;k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx >= 0 && ny >= 0 && nx <nn && ny < nn&&!visited[nx][ny]&&graph[nx][ny]!=0) {
                            q.push({ nx,ny });
                            cnt++;
                            visited[nx][ny] = true;
                        }
                    }
                }
                if (mmax < cnt)
                    mmax = cnt;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    nn = pow(2,n);
    for (int i = 0;i <nn;i++) {
        for (int j = 0;j < nn;j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0;i < q;i++) {
        int tmp;
        cin >> tmp;
        rotate(tmp);
        reduceIce();
        
    }
 
        findLump();
        cout << ssum << endl << mmax;
 

    return 0;
}