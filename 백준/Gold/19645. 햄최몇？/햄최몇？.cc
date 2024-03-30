#include <iostream>
#include <algorithm>
using namespace std;


const int N_MAX = 50;
const int T_MAX = 2500;


int n;
int a[N_MAX + 1];
bool dp[T_MAX + 1][T_MAX + 1];


int main() {
    int sum = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= 0; j--){
            for (int k = sum; k >= 0; k--) {
                if (j - a[i] >= 0) {
                    dp[j][k] |= dp[j - a[i]][k];
                }
                if (k - a[i] >= 0) {
                    dp[j][k] |= dp[j][k - a[i]];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= sum; i++) {
        for (int j = 0; j <= i; j++){
            if (dp[i][j] && j >= (sum - i - j)) {
                ans = max(ans, sum - i - j);
            }
        }
    }

    cout << ans;

    return 0;
}