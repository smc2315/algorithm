#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;

        }
        else
            return a.second > b.second;
    }
};
int main()
{
    int N;
    cin >> N;
    priority_queue<pair<int, int>,vector<pair<int,int>>,cmp> q;
    for (int i = 0; i < N; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        q.push({ n1,n2 });
    }
    int time = 0;
    int cnt = 0;
    while (!q.empty())
    {
        pair<int,int> tmp = q.top();
        q.pop();
        if (tmp.first >= time)
        {
            cnt++;
            time = tmp.second;
        }
    }
    cout << cnt;
return 0;
}