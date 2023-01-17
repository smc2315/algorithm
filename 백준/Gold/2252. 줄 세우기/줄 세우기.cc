#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX_SIZE 32000

vector<int> edge[MAX_SIZE];
int in[MAX_SIZE];
queue<int> q;

int main(void) {

    int n, m;

    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {

        cin >> a >> b;
        edge[a].push_back(b);
        in[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q.push(i);
    }

    while (!q.empty()) {

        int now = q.front();
        q.pop();
        cout << now << " ";

        for (int i = 0; i < edge[now].size(); i++) {

            int next_v = edge[now][i];

            in[next_v]--;
            if (in[next_v] == 0) q.push(next_v);
        }
    }

    return 0;
}