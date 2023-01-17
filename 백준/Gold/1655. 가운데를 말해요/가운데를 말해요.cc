#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
    int cur;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (i == 0) {
            cur = tmp;
        }
        else {
            if (tmp > cur) {
                pq2.push(tmp);
            }
            else
                pq1.push(tmp);
            if (pq2.size() > pq1.size() + 1) {
                pq1.push(cur);
                cur = pq2.top();
                pq2.pop();
                
            }
            else if (pq1.size() > pq2.size()) {
                pq2.push(cur);
                cur = pq1.top();
                pq1.pop();
            }
        }
        cout << cur << "\n";
        
    }

    return 0;
}