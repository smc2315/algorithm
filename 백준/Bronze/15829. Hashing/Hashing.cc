#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin>>s;
    long long sum=0;
    long long tmp =1;
    for(int i=0;i<n;i++)
        {
        sum+=((s[i]-96)*tmp)%1234567891;
        tmp*=31%1234567891;
        }
    cout<<sum;
    return 0;
    }
