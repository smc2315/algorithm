#include <iostream>
#include <vector>
#include <queue>


using namespace std;
int graph[101][101][101];
int visited[101][101][101];
int m, n, h;
int dx[6] = { 0,0,0,0,-1,1};
int dy[6] = { 0,0,-1,1,0,0 };
int dh[6] = { -1,1,0,0,0,0 };
struct point {
    int xx;
    int yy;
    int zz;
};
pair<int,int> bfs()
{
    int count = 0;
    queue<pair<point,int>> q;
    int ones = 0;
    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (graph[k][j][i] == 1)
                {
                    point p;
                    p.xx = k;
                    p.yy = j;
                    p.zz = i;
                   
                    ones++;
                    q.push({ p,count });
                    visited[k][j][i] = 1;
                }
            }
        }
    }
    while (!q.empty())
    {
        point cur = q.front().first;
        count = q.front().second;
       // cout << cur.xx <<" "<< cur.yy<<" " << cur.zz<<" " << count << endl;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            point p;
            p.xx= cur.xx + dx[i];
            p.yy = cur.yy + dy[i];
            p.zz = cur.zz + dh[i];
            if (p.xx < m && p.yy < n && p.zz < h && p.xx >= 0 && p.yy >= 0 && p.zz >= 0 && visited[p.xx][p.yy][p.zz] != 1 && graph[p.xx][p.yy][p.zz] != -1)
            {
                visited[p.xx][p.yy][p.zz] = 1;
                q.push({ p,count + 1 });
                ones++;
            }
        }
        
    }
    return { count,ones };

}
int main()
{

    cin >> m >> n >> h;
    bool check = false;
    int count = 0;
    for (int i = 0; i < h; i++)
    {
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
                graph[k][j][i] = num;
            }
        }
    }
    if (check == false)
    {
        cout << "0";
        return 0;
    }
    pair<int, int> result;
    result = bfs();
    if (count == result.second)
        cout << result.first << endl;
    else
        cout << "-1" << endl;
}
    