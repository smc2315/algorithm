#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[102][102];
int ans;
int main() {
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(arr[i][j] > arr[i][j-1]) {
                ans += (arr[i][j] - arr[i][j-1]) * 2;
            }
        }
    }
    for(int j=1;j<=M;j++){
        for(int i=1;i<=N;i++){
            if(arr[i][j] > arr[i-1][j]) {
                ans += (arr[i][j] - arr[i-1][j])*2;
            }
        }
    }
    ans += N*M*2;
    cout<<ans;
}