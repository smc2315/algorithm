#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


int n;
vector<pair<int, int>> v[10001];

int mmax = 0;
int maxNode;
void dfs(int start) {
    stack<pair<int, int>> stk;
    bool visited[10001];
    fill(visited, visited + n+1, false);

    stk.push({ start,0 });
    visited[start] = true;
   
    while (!stk.empty()) {
        int cur = stk.top().first;
        int cost = stk.top().second;
        //cout << cur << " ";
        if (cost > mmax) {
            mmax = cost;
            maxNode = cur;
        }
        stk.pop();

        for (int i = 0; i < v[cur].size(); i++) {
           
            if (!visited[v[cur][i].first]) {
                stk.push({ v[cur][i].first,v[cur][i].second + cost });
                visited[v[cur][i].first] = true;
                
            }
        }
    }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    dfs(1);
  // cout << endl;
    //cout << maxNode << " " << mmax << endl;
    mmax = 0;
    dfs(maxNode);
    cout << mmax;//<<" "<<maxNode;
    return 0;

   
}