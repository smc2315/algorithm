#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;
int t, n, k, goal;
vector<int> edge[MAX];
int inDegree[MAX]; 
int buildTime[MAX]; 
int dp[MAX]; 
void topologicalSort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            dp[i] = buildTime[i];
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int j = 0; j < edge[cur].size(); j++) {
            int next = edge[cur][j];
            dp[next] = max(dp[next],dp[cur] + buildTime[next]);
            if (--inDegree[next] == 0) {
                q.push(next);
            }
        }
    }
    cout << dp[goal] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {

        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> buildTime[i];
        }
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            edge[a].push_back(b);
            inDegree[b]++;
        }

        cin >> goal;
        topologicalSort();
        
        memset(edge, 0, sizeof(edge));
        memset(inDegree, 0, sizeof(inDegree));
        memset(buildTime, 0, sizeof(buildTime));
        memset(dp, 0, sizeof(dp));
    }



    return 0;
}