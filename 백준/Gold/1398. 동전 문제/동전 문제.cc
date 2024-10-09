#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int dp[101];
    dp[0] = 0;
    for(int i = 1; i <= 100; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i - 10 >= 0) {
            dp[i] = min(dp[i], dp[i - 10] + 1);
        }
        if (i - 25 >= 0) {
            dp[i] = min(dp[i], dp[i - 25] + 1);
        }
    }
    int T;
    cin>>T;
    while(T--) {
        long long N;
        cin >> N;
        int cnt = 0;
        while(N) {
            int cur = N % 100;
            cnt += dp[cur];
            N /= 100;
        }
        cout << cnt << endl;
    }
    return 0;
}