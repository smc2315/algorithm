#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int num, input;
    int count, ss=0;
    vector<int> v;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        count = 0;
        cin >> input;
        for (int j = 1; j <= input; j++)
        {
            if (input % j == 0)
            {
                count++;
            }
        }
        if (count == 2)
        {
            ss++;
        }


    }
    
    cout << ss;
    return 0;
}