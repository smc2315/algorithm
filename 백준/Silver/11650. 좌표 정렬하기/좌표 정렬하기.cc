#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<int, int> p;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    
    return 0;


}