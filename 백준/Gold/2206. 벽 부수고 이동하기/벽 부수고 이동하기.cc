#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int arr[1000][1000];
bool visited[2][1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct node {
    int x;
    int y;
    bool check;
    int cnt;
};

void bfs() {
    queue<node> q;
    node start = { 0,0,false,0 };
    q.push( start);
    visited[0][0][0] = true;
    int result = 1e9;
    while (!q.empty()) {
        pair<int, int> cur = { q.front().x,q.front().y };
        bool broke = q.front().check;
        int ccnt = q.front().cnt;
        
        if (cur.first == n-1&&cur.second==m-1) {
            if (result > ccnt)
                result = ccnt;
        }
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ddx = dx[i] + cur.first;
            int ddy = dy[i] + cur.second;
            if (broke) {
                if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < m && !visited[1][ddx][ddy]&&arr[ddx][ddy]!=1) {
                    
                    q.push({ ddx,ddy,broke,ccnt + 1 });
                    //cout << ddx << " " << ddy << endl;
                    visited[1][ddx][ddy] = true;
                    
                }
            }
            else {
                if ((ddx >= 0 && ddx < n && ddy >= 0 && ddy < m && !visited[0][ddx][ddy])) {
                    if (arr[ddx][ddy] == 1) {
                        q.push({ ddx,ddy,true,ccnt + 1 });
                        //cout << ddx << " " << ddy << endl;
                        visited[0][ddx][ddy] = true;
                    }
                    else {
                        q.push({ ddx,ddy,broke,ccnt + 1 });
                        //cout << ddx << " " << ddy << endl;
                        visited[0][ddx][ddy] = true;
                    }
                }

            }
        }
    }
    if (result == 1e9) {
        cout << "-1";
    }
    else
        cout << result + 1;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j] - '0';
        }
    }
    bfs();

    return 0;

   
}