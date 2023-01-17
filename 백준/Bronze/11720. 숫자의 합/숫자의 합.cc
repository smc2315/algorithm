#include <iostream>
using namespace std;
int main()
    {
    int n;
    char m[101];
    cin>>n;
    cin>>m;
    int sum=0;
    for(int i=0;i<n;i++)
        {
        sum+=(m[i]-'0');
        }
    cout<<sum;
    return 0;    
    }