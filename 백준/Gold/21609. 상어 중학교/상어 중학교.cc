#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, M;
int arr[21][21];
bool visited[21][21];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int ans = 0;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
}
bool find_biggest() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
    int mmax = 0;
    int x, y;
    int rainbow;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && arr[i][j] > 0) {
                int cur_color = arr[i][j];
                int cnt = 1;
                int cur_rainbow = 0;
                vector<pair<int, int>> rainbows;
                stack<pair<int, int>> stk;
                stk.push({ i,j });
                visited[i][j] = true;
                while (!stk.empty()) {
                    auto cur = stk.top();
                    stk.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < N && ny < N && arr[nx][ny] != -1 &&!visited[nx][ny] &&(arr[nx][ny] == 0 || arr[nx][ny] == cur_color)) {
                            stk.push({ nx,ny });
                            visited[nx][ny] = true;
                            if (arr[nx][ny] == 0) {
                                rainbows.push_back({ nx,ny });
                                cur_rainbow++;
                            }
                            cnt++;
                        }
                    }
                }
                for (int k = 0; k < cur_rainbow;k++) {
                    visited[rainbows[k].first][rainbows[k].second] = false;
                }
                if (cnt < 2)
                    continue;
                if (cnt > mmax) {
                    mmax = cnt;
                    x = i; y = j;
                    rainbow = cur_rainbow;
                }
                else if (cnt == mmax) {
                    if (rainbow < cur_rainbow) {
                        mmax = cnt;
                        x = i; y = j;
                        rainbow = cur_rainbow;
                    }
                    else if (rainbow == cur_rainbow) {
                        if (x < i) {
                            mmax = cnt;
                            x = i; y = j;
                            rainbow = cur_rainbow;
                        }
                        else if (x == i) {
                            if (y < j) {
                                mmax = cnt;
                                x = i; y = j;
                                rainbow = cur_rainbow;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (mmax < 2)
        return false;
    ans += mmax * mmax;
    stack<pair<int, int>> stk;
    stk.push({ x,y });
    int cur_color = arr[x][y];
    arr[x][y] = -2;
    while (!stk.empty()) {
        auto cur = stk.top();
        
        stk.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && (arr[nx][ny] == 0 || arr[nx][ny] == cur_color)) {
                stk.push({ nx,ny });
                arr[nx][ny] = -2;
            }
        }
    }
    return true;
}

void gravity() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == -2) {
                int x = i;
                while (x > 0 && arr[x - 1][j] != -1) {
                    arr[x][j] = arr[x - 1][j];
                    x--;
                }
                arr[x][j] = -2;
            }
        }
    }
}

void rotate() {
    int tmp[21][21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[N-j-1][i] = arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = tmp[i][j];
        }
    }

}
void print() {
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    while (find_biggest()) {
        
        gravity();
        rotate();
        gravity();
        
    }
    cout << ans;
    return 0;
}
