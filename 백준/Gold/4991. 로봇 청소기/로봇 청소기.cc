#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>

using namespace std;
struct node {
    int x;
    int y;
    int b;
    int dist=0;
};

int arr[21][21];
int n, m;
int cnt=0;
pair<int, int> start;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int visited[21][21][1 << 10];


void solve(map<pair<int,int>,int> mp) {
    memset(visited, 0, sizeof(visited));
    queue<node> q;
    node no;
    no.x = start.first;
    no.y = start.second;
    no.b = 0;

    q.push(no);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        //cout << cur.b << endl<<endl;
        if (cur.b == (1<<(cnt))-1) {
            cout << cur.dist<<"\n";
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int bm = cur.b;
            
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && arr[nx][ny] != 2) {
                if (arr[nx][ny] == 1) {
                    bm |= (1 << mp[{nx, ny}]);
                    //cout << mp[{nx, ny}] << endl;
                }
                //cout << bm << endl;
                if (!visited[nx][ny][bm]) {
                    visited[nx][ny][bm] = 1;
                    q.push({ nx,ny,bm,cur.dist+1 });
                }
                    


                
            }
        }

    }
    cout << "-1\n";
    return;
}

int main(int argc, char** argv){
    while (true) {
        cin >> n >> m;
        map<pair<int, int>, int > mp;
        if (n + m == 0)
            return 0;
        cnt = 0;
        for (int i = 0; i <m; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j <n; j++) {
                if (tmp[j] == '.')
                    arr[i][j] = 0;
                else if (tmp[j] == '*') {
                    arr[i][j] = 1;
                    mp[{i, j}] = cnt++;
                }
                else if (tmp[j] == 'x') {
                    arr[i][j] = 2;
                }
                else {
                    arr[i][j] = 0;
                    start = { i,j };
                }
            }
        }
        
        
        solve(mp);
    }
    return 0;
}