#include <iostream>
#include <queue>
#include <vector>
#include <queue>
using namespace std;

int n;
int graph[500][500];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int ddx[8] = { 0,1,1,1,0,-1,-1,-1 };
int ddy[8] = { -1,-1,0,1,1,1,0,-1 };
float percent[4] = { 0.1,0.01,0.01,0.1 };

int ans = 0;
void sand(int x,int y, int d) {
    int dd = 0;
    int ssum = 0;
    int blow = 0;
    for (int i = 0;i < 8;i++) {
        if (i == 4) {
            d++;
            continue;
        }
        else if (i == 0) {
            int nx = x + 2*ddx[d];
            int ny = y + 2 * ddy[d];
            int tmp = graph[x][y] * 0.05;
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                graph[nx][ny] += tmp;
                ssum += tmp;
            }
            else {
                ans+= tmp;
                blow+= tmp;
            }
        }
        else if (i == 2||i==6) {
            
            int nx = x + ddx[d];
            int ny = y + ddy[d];
            int tmp = graph[x][y] * 0.07;

            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                graph[nx][ny] += tmp;
                ssum += tmp;
            }
            else {
                ans += tmp;
                blow+= tmp;
            }
            tmp = graph[x][y] * 0.02;

            nx = nx + ddx[d];
            ny = ny + ddy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                graph[nx][ny] += tmp;
                ssum += tmp;
            }
            else {
                ans += tmp;
                blow+= tmp;
            }
        }
        else {
            int nx = x + ddx[d];
            int ny = y + ddy[d];
            int tmp = graph[x][y] * percent[dd / 2];
            //cout <<nx<<" "<<ny<<" "<< tmp << endl;
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                graph[nx][ny] += tmp;
                ssum += tmp;
            }
            else {
                ans += tmp;
                blow+= tmp;
            }
        }
        d++;
        dd++;
        d %= 8;

    }

  
    int nx = x + ddx[d];
    int ny = y + ddy[d];
    if (nx >= 0 && ny >= 0 && nx < n && ny < n)
        graph[x + ddx[d]][y + ddy[d]] += graph[x][y] - ssum-blow;
    else
        ans+= graph[x][y] - ssum-blow;
    graph[x][y] = 0;
}

void solve() {
    int sx = n / 2;
    int sy = n / 2;

    int t = 1;
    int d = 0;
   while(true) {
        for (int j = 0;j < 2;j++) {
            for (int k = 0;k < t;k++) {
                int nx = sx + dx[d];
                int ny = sy + dy[d];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    return;
                sx = nx;
                sy = ny;
                //cout << nx << " " << ny << endl;
                sand(nx, ny, d * 2);
                /*for (int i = 0;i < n;i++) {
                    for (int q = 0;q < n;q++) {
                        cout << graph[i][q] << " ";
                    }
                    cout << endl;
                }
                cout << ans<<endl;
                */
            }
            d++;
            d %= 4;
        }
        t++;
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> graph[i][j];
        }
    }
    solve();
    
    
    cout << ans;

    return 0;
}