#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
char map[51][51];
bool visited[51][51];
pair<int, int> D, S;

queue<pair<int,int>> water;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void input(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
            if (map[i][j] == 'S')
                S = {i, j};
            else if(map[i][j] =='*'){
                water.push({i,j});
            }
        }
    }
}

void spread_water(){
    int size = water.size();
    while(size--){
        auto cur = water.front();
        water.pop();
        for(int i=0;i<4;i++){
            int nx=cur.first+dx[i];
            int ny= cur.second+dy[i];
            if(nx>=0&&ny>=0&&nx<N&&ny<M&&map[nx][ny]!='X'&&map[nx][ny]!='*'&&map[nx][ny]!='D'){
                map[nx][ny] = '*';
                water.push({nx,ny});
            }
        }
    }
}

void print_map(){
    cout<<endl;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int solution(){
    queue<pair<int, int>> q;
    q.push(S);
    visited[S.first][S.second] = true;
    int cnt = 0;
    while (!q.empty()){
        int size = q.size();
        spread_water();
        while(size--){
            auto cur = q.front();
            q.pop();
            if(map[cur.first][cur.second] == 'D'){
                return cnt;
            }
            for (int i = 0; i < 4; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && map[nx][ny] != '*' && map[nx][ny] != 'X'){
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
        
        cnt++;
    }
    return -1;
}

void solve(){
    input();
    int ans = solution();
    if(ans == -1){
        cout<<"KAKTUS";
        return;
    }
    else {
        cout<<ans;
        return;
    }
}

int main(){
    solve();
}