#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0;i < n;i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    int answer = 0;
    int tmp;
    if (pq.size() == 1) {
        cout << 0;
        return 0;
    }
    while (!pq.empty()) {

        if (answer == 0) {
            answer += pq.top();pq.pop();

            answer += pq.top();pq.pop();
            tmp = answer;

        }
        else {
            int cur = pq.top();
            pq.pop();
            int cur2 = 0;
            if (!pq.empty()) {
                cur2 = pq.top();
            }
            if (cur2 != 0) {
                if (cur2 < tmp) {
                    
                    answer += cur+cur2;
                    pq.pop();
                    pq.push(cur+cur2);
                }
                else {
                    tmp += cur;
                    answer += tmp;
                }
            }
            else {
                answer += tmp + cur;
            }
        }
        //cout <<tmp<< " "<< answer <<endl;
    }
    cout << answer;
    return 0;

}