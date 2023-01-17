#include <iostream>
#include <stack>
using namespace std;
int main()
    {
    stack<int> stk;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        {
        int m;
        cin>>m;
        if(m==0)
           stk.pop();
        else
            stk.push(m);
        }
    int sum=0;
    while(!stk.empty())
        {
        sum+=stk.top();
        stk.pop();
        }
    cout<<sum;
    return 0;
    }