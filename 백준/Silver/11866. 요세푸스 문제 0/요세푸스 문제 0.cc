#include <iostream>
#include<string>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n,k;
    queue<int> q;
    cin >> n>>k;
    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }
    cout << "<";
    int cur = k - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <k-1; j++)
        {
            int num;
            num = q.front();
            q.pop();
            q.push(num);
        }
        if (i != n - 1)
        {
            cout << q.front() << ", ";
        }
        else
            cout << q.front();
        q.pop();
        cur += k;
    }
    cout << ">";
    return 0;


}