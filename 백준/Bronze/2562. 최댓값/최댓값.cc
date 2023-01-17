#include <iostream>
using namespace std;
int main()
{
    int n;
    int big =0;
    int index;
    for(int i=0;i<9;i++)
    {
        cin >> n;
        if(big<n)
        {
            big = n;
            index = i;
        }
    }
    cout << big<<endl<<index+1;
    return 0;
}