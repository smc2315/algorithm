#include <iostream>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int main() {
    cin >> N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }

    
    for (int i = 1; i <= N; i++){
        dp[i] = 1;
        for (int j = 1; j <= i; j++){
            if (arr[i] < arr[j] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }
    int mmax = 0;
    for(int i=1;i<=N;i++){
        if(mmax < dp[i])
            mmax = dp[i];
    }
    cout<<mmax;
    return 0;
}