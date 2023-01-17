#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
int main()
{
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> q;
    q.push({ n,0 });
    visited[n] = true;
    int ans = 0;
    while (!q.empty())
    {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();
        if (cur == k)
        {
            ans = time;
            break;
        }
        if (cur-1>=0 && visited[cur - 1] != true)
        {
            q.push({ cur - 1,time + 1 });
            visited[cur - 1] = true;
        }
        if (cur + 1 <= 100000 && visited[cur + 1] != true)
        {
            q.push({ cur + 1,time + 1 });
            visited[cur + 1] = true;
        }
        if (cur * 2 <= 100000 && visited[cur * 2] != true)
        {
            q.push({ cur * 2,time + 1 });
            visited[cur * 2] = true;
        }
    }

cout << ans;
return 0;
}