#include <iostream>
using namespace std;
int main()
{
    int n;
    int mul = 1;
    int arr[10] = { 0, };
    for (int i = 0; i < 3; i++)
    {
        cin >> n;
        mul *= n;
    }
    for (int i = 0; i < 70; i++)
    {
        arr[mul % 10]++;
        mul /= 10;
        if (mul < 1)
            break;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
}