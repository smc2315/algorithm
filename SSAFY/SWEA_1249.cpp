#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int N;
int arr[101][101];
int visited[101][101];
 
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void bfs(){
     
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 0;
    int ret = 1e9;
   while(!q.empty()){
       auto cur = q.front();
       q.pop();
        
       for(int i=0;i<4;i++){
           int nx = cur.first+dx[i];
           int ny = cur.second+dy[i];
           if(nx>=0&&ny>=0&&nx<N&&ny<N){
               if(visited[nx][ny]>visited[cur.first][cur.second]+arr[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny] =visited[cur.first][cur.second]+arr[nx][ny];
               }
           
           }
       }
                 
   }
    
     
}
 
int main(int argc, char** argv)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int test_case;
    int T;
 
    cin>>T;
 
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>N;
        for(int i=0;i<N;i++){
            string tmp;
            cin>>tmp;
            for(int j=0;j<N;j++){
                arr[i][j] = tmp[j]-'0';
                visited[i][j] = 1e9;
            }
        }
        bfs();
        cout<<"#"<<test_case<<" "<<visited[N-1][N-1]<<"\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
