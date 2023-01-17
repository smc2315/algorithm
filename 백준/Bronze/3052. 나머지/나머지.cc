#include <iostream>
using namespace std;
int main()
    {
    int arr[42]={0,};
    int cnt=0;
    for(int i=0;i<10;i++)
        {
        int n;
        cin>>n;
        if(arr[n%42]==0)
           cnt++;
        arr[n%42]++;
        }
    cout<<cnt;
    return 0;
         
    }