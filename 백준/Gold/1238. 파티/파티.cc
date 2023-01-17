#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9 


int n, m, x;

vector<pair<int, int> > graph[1001]; 
int d[1001][1001]; 

void dijkstra(int start)
{
    priority_queue<pair<int, int>>pq; 

    pq.push({ 0,start }); 
    d[start][start] = 0;

    while (!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[start][now] < dist) 
            continue;

        for (int i = 0; i < graph[now].size(); i++)
        {
            int cost = dist + graph[now][i].second; 
            if (cost < d[start][graph[now][i].first]) 
            {
                d[start][graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }
    }
}

int main(void)
{
    cin >> n >> m >> x;

    
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        graph[a].push_back({ b, c });
    }

    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            d[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }
    int mmax = 0;
    for (int i = 1; i <= n; i++) {
        //cout << d[i][2] + d[2][i] << endl;
        if (mmax < d[i][x] + d[x][i])
            mmax = d[i][x] + d[x][i];
    }
    cout << mmax;
}