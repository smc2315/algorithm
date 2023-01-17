#include <iostream>
#include<string>
using namespace std;
char chess[50][50];
char check1[8][8] = {{'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'} };
char check2[8][8] = { {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'} };

int main()
{
    int n, m;
    string s;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            chess[i][j] = s[j];
    }
    int result = 10000;
    for (int i = 0; i < n - 7; i++)
    {
        
        for (int j = 0; j < m - 7; j++)
        {
            int cnt = 0;
            int cnt1 = 0;
            int cnt2 = 0;
            for (int l = i; l < i + 8; l++)
            {
                
                for (int k = j; k < j + 8; k++)
                {
                    if(check1[l - i][k - j] != chess[l][k])
                    {
                        cnt1++;
                    }
                    if (check2[l - i][k - j] != chess[l][k])
                    {
                        cnt2++;
                    }
                }
                
            }
            cnt = (cnt1 < cnt2) ? cnt1 : cnt2;
            if (result > cnt)
                result = cnt;
            
        }

    }
    cout << result;
    return 0;


}