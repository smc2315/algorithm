#include <iostream>
#include <queue>

using namespace std;

int a,b,N,M;
int ans=1e9;
int visited[1001];
vector<int>v[1001];

void bfs(int start,int depth){
    queue<pair<int,int>>q;
    q.push({start,depth});
    visited[start]=1;
    while(!q.empty()){
        int start=q.front().first;
        int depth=q.front().second;
        q.pop();

        if(start==b){
            ans=min(depth,ans);
        }
        for(int i=0; i<v[start].size(); i++){
            if(!visited[v[start][i]]){
                q.push({v[start][i],depth+1});
                visited[v[start][i]]=1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b>>N>>M;
    for(int i=0; i<M; i++){
        int inp1,inp2; cin>>inp1>>inp2;
        v[inp1].push_back(inp2);
        v[inp2].push_back(inp1);
    }

    bfs(a,0);
    if(ans==1e9) cout<<-1;
    else cout<<ans;
}