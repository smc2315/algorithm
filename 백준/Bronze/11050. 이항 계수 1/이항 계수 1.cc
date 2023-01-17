#include <iostream>
#include<string>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n,k;
    cin >> n>>k;
    float sum = 1;
    int div = k;
    for (int i = 0; i < k; i++)
    {
        sum *= n--;
        sum /= div--;
        
    }
    cout << sum;
    
    return 0;


}