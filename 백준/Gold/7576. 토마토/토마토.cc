#include <iostream>
#include <vector>
#include <queue>


using namespace std;
int graph[1001][1001];
int visited[1001][1001];
int m, n;
int dx[6] = { 0,0,-1,1};
int dy[6] = { -1,1,0,0 };

pair<int,int> bfs()
{
    int count = 0;
    queue<pair<pair<int,int>,int>> q;
    int ones = 0;
    
   
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < m; k++)
        {
            if (graph[k][j] == 1)
            {
                pair<int,int> p;
                p.first = k;
                p.second = j;
            
                   
                ones++;
                q.push({ p,count });
                visited[k][j] = 1;
            }
        }
    }
    
    while (!q.empty())
    {
        pair<int, int> cur= q.front().first;
        count = q.front().second;
        //cout << cur.first <<" "<< cur.second<<" " << cur.first<<" " << count << endl;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int,int> p;
            p.first= cur.first + dx[i];
            p.second = cur.second + dy[i];
            if (p.first < m && p.second < n && p.first >= 0 && p.second >= 0  && visited[p.first][p.second] != 1 && graph[p.first][p.second] != -1)
            {
                visited[p.first][p.second] = 1;
                q.push({ p,count + 1 });
                ones++;
            }
        }
        
    }
    return { count,ones };

}
int main()
{
    
    cin >> m >> n;
    bool check = false;
    int count=0;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < m; k++)
        {
            int num;
            cin >> num;
            if (num == 0)
                check = true;
            if (num != -1)
                count++;
            graph[k][j] = num;
        }
    }
    
    if (check == false)
    {
        cout << "0";
        return 0;
    }
    pair<int,int> result;
    result = bfs();
    if (count == result.second)
        cout << result.first<<endl;
    else
        cout << "-1"<<endl;
   // cout << result.second << " " << count;
}