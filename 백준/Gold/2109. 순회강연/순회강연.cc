
#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
priority_queue<int> pq;
int N;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a,b;
        cin >> a>>b;
        v.push_back({ b,a });
    }
    sort(v.begin(), v.end());
    
    int res = 0;

    for (int i =0; i < N ; i++) {
        pq.push(-v[i].second);
        res += v[i].second;

        if (pq.size() > v[i].first) {
            res += pq.top();
            pq.pop();
        }
    }
    //res += pq.top();

    
    cout << res;
    return 0;
}