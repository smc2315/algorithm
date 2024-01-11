#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[2501];
string s;
bool is_palin(int start, int end) {
    while(start < end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    
    cin >> s;

    dp[1] = 1;
    for(int i = 2; i <= s.length();i++) {
        dp[i] = dp[i - 1] + 1;
        for(int j = 1; j < i; j++) {
            if(is_palin(j - 1, i - 1)) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[s.length()];
    return 0;
}