#include <iostream>
#include <queue>

using namespace std;

int n,m;
int arr[51][51];
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int count_island(){
    bool visited[51][51];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = false;
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                cnt++;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int k=0;k<8;k++){
                        int nx = cur.first+dx[k];
                        int ny = cur.second+dy[k];
                        if(nx>=0&&ny>=0&&nx<n&&ny<m&&arr[nx][ny]==1&&!visited[nx][ny]){
                            q.push({nx,ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main() {
    while(true) {
        cin>>m>>n;
        if((n|m)==0)
            break;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>arr[i][j];
            }
        }
        cout<<count_island()<<endl;
    }
}