#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    queue<int> q1;
    queue<int> q2;
    long long sum1 = 0;
    long long sum2 = 0;
    for(int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
        
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    int cnt = 0;
    while(sum1 != sum2) {
        if(cnt > 3 * queue1.size()) {
            return -1;
        }
        if(sum1 > sum2) {
            int tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            sum1 -= tmp;
            sum2 += tmp;
        }
        else {
            int tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            sum2 -= tmp;
            sum1 += tmp;
        }
        cnt++;
    }
    return cnt;
}