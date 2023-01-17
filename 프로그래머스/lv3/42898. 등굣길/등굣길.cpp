#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    long long answer = 0;
    long long v[100][100];
    for(int i=0;i<puddles.size();i++){
        v[puddles[i][0]-1][puddles[i][1]-1]=-1;
    }
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    v[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0)
                continue;
            if(v[i][j]==-1){
                v[i][j]=0;
                continue;
            }
            v[i][j] = ((i>0?v[i-1][j]:0)+(j>0?v[i][j-1]:0))%1000000007;
        }
    }
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return v[m-1][n-1];
}