#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
long long arr[1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long answer = 0;

    cin >> N >> M;

    int ssum = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (i == 0) {
            ssum = tmp % M;
        }
        else {
            ssum += tmp%M;
            ssum %= M;
        }
        
        arr[ssum]++;
    }

    answer += arr[0];
    for (int i = 0; i < M; i++) {
        
        answer += arr[i] * (arr[i]-1) / 2;
    }
    cout << answer;
    return 0;
}
