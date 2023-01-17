#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int newn=0, newm=0;
    newm = m - 45;
    newn = n;
    if (newm < 0)
    {
        newm = 60 + newm;
        newn = newn - 1;
        if (newn < 0)
            newn = 24 + newn;
    }
    cout << newn << " " << newm;
    return 0;
}