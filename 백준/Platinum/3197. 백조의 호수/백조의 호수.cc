#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int R, C, ans;
char map [1501][1501];
bool visited[1501][1501];

queue<pair<int, int>> q,nq,swanQ,swanNQ;

pair<int,int> swan;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
void melt() {
    while (!q.empty()) {
       auto cur = q.front();
       
       q.pop();
       for (int i = 0; i < 4; i++) {
           int nx = cur.first + dx[i];
           int ny = cur.second + dy[i];
           if (nx >= 0 && ny >= 0 && nx < R && ny < C ) {
               if (map[nx][ny] == 'X') {
                   map[nx][ny] = '.';
                   nq.push({ nx,ny });
               }
              
           }
       }
    }
   
    q = nq;
    while (!nq.empty()) {
        nq.pop();
    }
}

bool canMeet() {
    
   
    while (!swanQ.empty()) {
        
        auto cur = swanQ.front();
        
        swanQ.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < R && ny < C && !visited[nx][ny]) {
                if (map[nx][ny] == 'L') 
                    return true;
                else if (map[nx][ny] == '.')
                    swanQ.push({ nx,ny });
                else
                    swanNQ.push({ nx,ny });
                visited[nx][ny] = true;
            }
        }
    }
    swanQ = swanNQ;
    while (!swanNQ.empty()) {
        
        swanNQ.pop();
    }
    return false;
}

void solve() {
    swanQ.push({ swan });
    visited[swan.first][swan.second] = true;
    while (!canMeet()) {
    
        melt();
       
        ans++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] != 'X') {
                q.push({ i,j });
            }
            if (map[i][j] == 'L') {
                swan = { i,j };
            }
        }
    }
    
    solve();
    cout << ans;
    return 0;

}