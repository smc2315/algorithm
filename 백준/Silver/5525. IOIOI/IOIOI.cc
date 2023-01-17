#include <iostream>
#include <vector>
#include <deque>
#include<string>
using namespace std;


int main()
{

    int n,m;
    int cnt = 0;
    cin >> n>>m;
    string s1="";
    string s2;
    for (int i = 0; i < n; i++)
        s1 += "IO";
    s1 += "I";
    cin >> s2;
    for (int i = 0; i < m; i++)
    {
        
        if (s2[i] == 'I')
        {
            
            if (s2.substr(i, s1.length()) == s1)
            {
                cnt++;
            }
        }
       
    }
    cout << cnt;

    
    
return 0;
}