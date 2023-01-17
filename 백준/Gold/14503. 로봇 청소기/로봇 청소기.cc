#include <iostream>
#include <string.h>
#include <vector>
#include<queue>
using namespace std;


int n, m,r,c,d;
int graph[51][51];
bool visited[51][51] = { 0, };
int ans = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void clean() {
    if (graph[r][c] != 1 && !visited[r][c]) {
        visited[r][c] = true;
        ans++;

    }


}

void search(int cnt) {
    if (cnt == 4) {
        if (graph[r - dx[d]][c - dy[d]] == 1)
            return;
        else {
            r = r - dx[d];
            c = c - dy[d];
            search(0);
        }
    }
    
    else {
        int nextD = (d + 3) % 4;
        int nextX = r + dx[nextD];
        int nextY = c + dy[nextD];
        //nextX >= 0 && nextY >= 0 && nextX < n&& nextY < m&&
        if (graph[nextX][nextY] != 1) {
            if (!visited[nextX][nextY]) {
                d = nextD;
                r = nextX;
                c = nextY;
                clean();
                search(0);
            }
            else {
                d = nextD;
                search(cnt + 1);
            }
        }
        else {
            d = nextD;
            search(cnt + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> graph[i][j];
        }
    }
    clean();
    search(0);
    cout << ans;
   
    return 0;
}