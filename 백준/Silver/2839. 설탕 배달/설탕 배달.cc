#include<iostream>
#include<vector>

using namespace std;


int main(void) 
{
    int N;
    cin >> N;

    int count = 0;
    int i = 0;
    int n;
    while (true)
    {

        n = N - 5*i;
        if (n <= 2) break;
        if (n % 3 == 0)
        {
            count = n / 3 + i;
           

        }
        i++;
    }
    if (count == 0)
        count = -1;
    if (N % 5 == 0)
        count = N / 5;
    cout << count;
    
    

    return 0;
}