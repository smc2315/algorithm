#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<double> v;
    int big = 0;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (m > big)
            big = m;
        v.push_back(m);
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= big)
            v[i] = double(v[i]) / double(big) * 100;
    }
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }

    cout << sum / n;
    return 0;
}