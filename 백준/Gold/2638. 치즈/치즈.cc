#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m;
int arr[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int air[101][101];


void checkAir() {
    queue<pair<int,int>> q;
    q.push({ 0,0 });
    air[0][0] = -1;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ddx = cur.first + dx[i];
            int ddy = cur.second + dy[i];
            if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < m && arr[ddx][ddy] == 0 && air[ddx][ddy]!=-1) {
                q.push({ ddx,ddy });
                air[ddx][ddy] = -1;
            }
        }
    }
}
bool cheese() {
    bool check = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            if (arr[i][j] == 1) {
                check = true;
                for (int k = 0; k < 4; k++) {
                    int ddx = i + dx[k];
                    int ddy = j + dy[k];
                    if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < m && air[ddx][ddy] == -1) {
                        cnt++;
                    }
                }
                if (cnt >= 2) {
                    arr[i][j] = 0;
                }
            }
        }
    }
    return check;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int result = 0;
    while (true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                air[i][j] = 0;
            }
        }
        checkAir();
        if (!cheese()) {
            break;
        }
        result++;
        
    }
    cout << result;
   

    return 0;

   
}