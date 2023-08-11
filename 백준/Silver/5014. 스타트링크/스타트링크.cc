#include <iostream>
#include <queue>
using namespace std;

int F,S,G,U,D;
bool visited[1000001];
int bfs(){
    queue<int> q;
    q.push(S);
    visited[S] = true;
    int cnt = 0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int cur = q.front();
            if(cur == G){
                return cnt;
            }
            q.pop();
            int nu = cur + U;
            int nd = cur - D;
            if(nu<=F && !visited[nu]){
                visited[nu] = true;
                q.push(nu);
            }
            if(nd>0 && !visited[nd]){
                visited[nd] = true;
                q.push(nd);
            }
        }
        cnt++;
    }
    return -1;
}
int main() {
    cin>>F>>S>>G>>U>>D;
    int tmp = bfs();
    if(tmp == -1){
        cout<<"use the stairs";
        return 0;
    }
    cout<<tmp;
    return 0;
}