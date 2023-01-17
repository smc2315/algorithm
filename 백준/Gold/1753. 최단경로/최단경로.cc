#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9 

int n,m;
vector<pair<int, int> > graph[20001];  
int dist[20001];
void dijkstra(int start)
{
    priority_queue<pair<int, int>>pq; 
    pq.push({0,start });
    dist[start] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second;
        int len = -pq.top().first;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int cost = len + graph[cur][i].second;
            if (cost < dist[graph[cur][i].first]) {
                dist[graph[cur][i].first] = cost;
                pq.push({ -cost,graph[cur][i].first });
            }
        }

    }


   
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int start;
    cin >> start;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dijkstra(start);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "INF" << "\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }
   
}