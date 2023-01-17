#include <iostream>

using namespace std;

int N,K;
long long dp[201][201];

int main(){
    cin>>N>>K;
    
    for(int i=0;i<=N;i++){
       dp[i][1] = 1;
    }
    for(int k=2;k<=K;k++){
        for(int i=0;i<=N;i++){
            for(int j=0;j<=i;j++){
                dp[i][k] = (dp[i][k]+dp[j][k-1])%1000000000;
                
            }
        }
        
    }
    cout<<dp[N][K];
    return 0;
}