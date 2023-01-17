#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;




int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v(500);
    int dp[501];
    int n;
    cin >> n;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for(int j=0;j<cnt;j++) {
            int m;
            cin >> m;
            if (i == 0) {
                v[i].push_back(m);
            }
            else if (j==0) {
                v[i].push_back(m+v[i-1][j]);
            }
            else if(j!=cnt-1){
                v[i].push_back(m + max(v[i - 1][j-1],v[i-1][j]));
            }
            else {
                v[i].push_back(m + v[i - 1][j - 1]);
            }
        }
        cnt++;
    }
    int mmax = 0;
    for (int i = 0; i < v[n - 1].size(); i++) {
        if (v[n - 1][i] > mmax)
            mmax = v[n - 1][i];
    }
    cout << mmax;

    return 0;

   
}