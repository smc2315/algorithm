#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vv;
    for (int i = 0;i < n;i++) {
        int m, v;
        cin >> m >> v;
        vv.push_back({ m,v });

    }
    vector<int> ks;
    for (int i = 0;i < k;i++) {
        int num;
        cin >> num;
        ks.push_back(num);
    }
    sort(ks.begin(), ks.end());
    sort(vv.begin(), vv.end());

    long long answer = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    int j = 0;
    for (auto i : ks) {
 
        while (j < vv.size()) {
            if (vv[j].first <= i) {
                pq.push(vv[j++].second);
            }
            else
                break;
        }
        if (pq.empty()) {
            continue;
        }
        else {
            answer += (long long)pq.top();
            pq.pop();
        }

    }
    cout << answer;
    return 0;

}