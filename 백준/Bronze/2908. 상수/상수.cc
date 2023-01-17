#include <iostream>
using namespace std;
int main()
    {
    int n,m;
    cin>>n>>m;
    int newn=0,newm=0;
    newn+=((n%10)*100);
    newm+=((m%10)*100);
    n/=10;
    m/=10;
    newn+=((n%10)*10);
    newm+=((m%10)*10);
    n/=10;
    m/=10;
    newn+=((n%10));
    newm+=((m%10));
    if(newm>newn)
      cout<<newm;
    else
        cout<<newn;
    
    }