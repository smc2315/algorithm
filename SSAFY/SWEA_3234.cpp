#include<iostream>
#include <vector>
#include <cmath>
using namespace std;
 
int answer = 0;
int v[9];
bool b[9];
int N;
int sum=0;
int exponential[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
int factorial[] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
void solve(int cnt,int R,int L ){
    if(L>sum-L){
        int tmp = N-cnt;
        int tmp2=exponential[tmp];
        answer+=tmp2*factorial[tmp];
        return;
    }
    for(int i=0;i<N;i++){
        if(cnt==0){
            b[i] = true;
            solve(cnt+1,R,L+v[i]);
            b[i] = false;
        }
        else if(!b[i]){
            b[i] = true;
            if(R+v[i]<=L){
                if(cnt==N-1){
                    answer++;
                }
                else{
                    solve(cnt+1,R+v[i],L);
                }
            }
            if(cnt == N-1){
                answer++;
                 
            }
            else{
                solve(cnt+1,R,L+v[i]);
                
            }
             b[i] = false;
        }
    }
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
         
        cin>>N;
        sum=0;
        for(int i=0;i<N;i++){
            cin>>v[i];
            sum+=v[i];
            b[i] = false;
        }
        answer= 0;
        solve(0,0,0);
        cout<<"#"<<test_case<<" "<<answer<<"\n";
         
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
