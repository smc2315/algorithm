#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int graph[101][101];
bool visited[101];
int cnt = 0;
void dfs(int start,int num)
{
    stack<int> stk;
    stk.push(start);
    visited[start] = true;
    while (!stk.empty())
    {

        int tmp = stk.top();
        stk.pop();
        for (int i = 0; i < num; i++)
        {
            if (graph[tmp][i] == 1&&visited[i]==false)
            {
                stk.push(i);
                cnt++;
                
                visited[i] = true;

            }
        }
    }
}
int main()
{
    int n,m;
    cin >>n>>m;
   
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a>>b;
        graph[a - 1][b - 1] = 1;

        graph[b - 1][a - 1] = 1;

    }
    dfs(0,n);
    cout << cnt;
return 0;
}