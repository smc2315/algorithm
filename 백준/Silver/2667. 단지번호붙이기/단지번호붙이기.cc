#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
#include<string>
using namespace std;
int paper[26][26];
bool visited[26][26];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int total = 0;
vector<int> result;

void bfs(int x,int y, int num)
{
   
    int cnt = 0;
    queue<pair<int, int> >q;
    q.push({ x,y });
    visited[x][y] = true;
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        //cout << "xx: " << xx << "yy: " << yy << endl;
        
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if(xx+dx[i] >= 0 && xx+dx[i] < num  && yy+dy[i]>=0&&yy+dy[i]<num)
                if (visited[xx + dx[i]][yy + dy[i]] == false && paper[xx+dx[i]][yy+dy[i]] == 1)
                {
                    q.push({ xx + dx[i],yy + dy[i] });
                    visited[xx + dx[i]][yy + dy[i]] = true;
                    cnt++;
                }
        }

    }
    result.push_back(cnt);
    total++;

}
int main()
{
    int n;
    cin >>n;
   
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            paper[i][j] = s[j] - '0';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (paper[i][j] == 1 && visited[i][j] == false)
            {
                //cout << i << " " << j;
                bfs(i, j, n);
            }
        }
    }
    cout << total << endl;
    sort(result.begin(), result.end());
    for (int i : result)
        cout << i+1 << endl;
return 0;
}