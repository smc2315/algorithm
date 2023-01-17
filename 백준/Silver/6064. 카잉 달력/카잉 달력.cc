#include <iostream>
#include<algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    int x, y, m, n;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> m >> n >> x >> y;
        bool check = false;
        x--;
        y--;
        for (int j = x; j < m * n; j += m)
        {
            if (j % n == y)
            {
                cout << j+1<< "\n";
                check = true;
                break;
            }

        }
        if (check == false)
            cout << "-1" << "\n";
    }





    return 0;
}