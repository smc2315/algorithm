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
        int a,b;
        cin >> a >> b;
        v.push_back({ -a,b });
    }
    sort(v.begin(), v.end());
    priority_queue<int> pq;
    int res = 0;
    int day = -v[0].first;

    int i = 0;
    while(true) {
        if (day == 0)
            break;
        //cout << day << " " << -v[i].first << endl;
        while (i < N && -v[i].first == day) {
            pq.push(v[i].second);
            i++;
        }
        
        if (!pq.empty()) {
            res += pq.top();
            pq.pop();
            
        }
        day--;
    }
    cout << res;

    return 0;
}