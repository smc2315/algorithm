#include <iostream>
#include <vector>
using namespace std;
int paper[129][129];
int result[2];

void cut(int x, int y,int num)
{
    int tmp = paper[x][y];

    bool check = true;
    for (int i = x; i < x + num; i++)
    {
        for (int j = y; j < y + num; j++)
        {
            if (paper[i][j] != tmp)
            {
                check = false;
                break;
            }
            
        }
        if (check == false)
            break;
    }
    if (check == false)
    {
        for(int i=0;i<2;i++)
            for (int j = 0; j < 2; j++)
            {
                cut(x+i * (num / 2),y+ j * (num / 2), num / 2);
            }
    }
    else
    {
        result[tmp]++;
       
    }
}
int main()
{
    int n;
    cin >>n;
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           
            cin >> paper[i][j];
        }
    }
    cut(0, 0, n);
    cout << result[0] <<endl<< result[1];
return 0;
}