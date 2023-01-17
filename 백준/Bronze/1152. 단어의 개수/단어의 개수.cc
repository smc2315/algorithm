#include <iostream>
#include <vector>
#include<string>
using namespace std;


int main()
{
    string s;
    getline(cin, s);
    int cnt = 0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i] == ' ')
            cnt++;
    }
    
    if (s[0] == ' ')
        cnt--;
    if (s[s.length() - 1] == ' ')
        cnt--;
    cout << cnt + 1;
    return 0;
}