#include <iostream>
#include <string>
using namespace std;
int main()
    {
    int num;
    cin >> num;
    int sum=0;
    for(int i=0;i<num;i++)
        {
        sum=0;
        string s;
        int cnt=1;
        cin>>s;
        for(int j=0;j<s.length();j++)
            {
            if(s[j] == 'O')
                sum+=cnt++;
            else
                cnt =1;
            }
        cout<<sum<<endl;
        }

    return 0;
    }