#include<iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 1e9 
using namespace std;

int aa,bb,ss;
int ans=1e9;
vector<pair<int, int> > graph[201];
void dijkstra(int start){
    priority_queue<pair<int,int>>pq; 
    int d[201];
    fill(d,d+201,INF);
    pq.push({0,start});
    d[start]=0;
    
    while(!pq.empty())
    {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(d[now]<dist) 
            continue;
        
        for(int i=0; i<graph[now].size(); i++)
        {
            int cost = dist+graph[now][i].second; 
                                                
            if(cost<d[graph[now][i].first]) 
            {
                d[graph[now][i].first]=cost;
                pq.push(make_pair(-cost,graph[now][i].first));
            }
        }
    }
    int sum;
    if(d[ss]<INF&&d[aa]<INF&&d[bb]<INF)
        sum = d[ss]+d[aa]+d[bb];

    cout<<endl;
    
    if(sum<ans)
        ans=sum;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    int answer = 0;
    aa=a-1;
    bb=b-1;
    ss=s-1;
    for(int i=0;i<fares.size();i++){
        graph[fares[i][0]-1].push_back({fares[i][1]-1,fares[i][2]});
        graph[fares[i][1]-1].push_back({fares[i][0]-1,fares[i][2]});
    }
    for(int i=0;i<n;i++){
        dijkstra(i);
    }
    
    return ans;
}