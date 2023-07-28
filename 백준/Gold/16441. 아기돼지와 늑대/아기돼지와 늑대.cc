#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
char map[101][101];
bool visited[101][101];
vector<pair<int,int>> wolf;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

void bfs() {
    queue<pair<int,int>> q;
    for(int i=0;i<wolf.size();i++){
        q.push(wolf[i]);
        visited[wolf[i].first][wolf[i].second] = true;
    }
    

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && map[nx][ny] != '#') {
                if(map[nx][ny] == '+') {
                    while(map[nx][ny] == '+'){
                        nx+=dx[i];
                        ny+=dy[i];
                    }
                    if(map[nx][ny] == '.' && !visited[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx,ny});
                    }
                    else if(map[nx][ny] == '#' && !visited[nx-dx[i]][ny-dy[i]]){
                        visited[nx-dx[i]][ny-dy[i]] = true;
                        q.push({nx-dx[i],ny-dy[i]});
                    }
                }
                else {
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }
    }

}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            map[i][j] = s[j];
            if(map[i][j] == 'W') {
                wolf.push_back({i,j});
            }
        }
    }
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && map[i][j] == '.'){
                cout<<'P';
            }
            else{
                cout<<map[i][j];
            }
        }
        cout<<endl;
    }
}