#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        int m;
        string s;
        cin >>m>>s;
        for(int j=0;j<s.size();j++)
        {
            for(int k=0;k<m;k++)
            {
                cout<<s[j];
            }
        }
        cout << endl;
    }
    return 0;
}