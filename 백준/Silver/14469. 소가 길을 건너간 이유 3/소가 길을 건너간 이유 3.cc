#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    int start = v[0].first;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first > start) {
            start = v[i].first;
           
        }
        start += v[i].second;
    }
    cout << start;
    return 0;
}