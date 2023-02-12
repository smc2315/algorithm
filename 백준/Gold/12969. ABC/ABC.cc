#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int dp[453][31][31][31];
int N,K;
int ans[31];


void input() {
    cin >> N>>K;
    memset(dp, -1, sizeof(dp));
}

int solution(int k, int a,int b, int c) {
    if (a + b + c == N)
        return !k ? 1 : 0;
    if (k <= 0)
        return 0;
    int& res = dp[k][a][b][c];
    if (res != -1)
        return res;
    ans[a + b + c] = 0;
    if (solution(k, a + 1, b, c))
        return res = 1;
    ans[a + b + c] = 1;
    if (solution(k - a, a, b + 1, c))
        return res = 1;;
    ans[a + b + c] = 2;
    if (solution(k - a - b, a, b, c + 1))
        return res = 1;
    return res = 0;
}



void solve() {
    input();
    if (!K) {
        for (int i = 0; i < N; i++) {
            cout << 'A';
        }
        return;
    }
    if (!solution(K, 0, 0, 0)) {
        cout << -1;
        return;
    }
    for (int i = 0; i < N; i++) {
        cout << (char)(ans[i] + 'A');
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    
    
   
    return 0;

}