#include <iostream>

using namespace std;
int N,M;
int arr[101];
void solve(int g, int idx){
    if(g==1){
        int tmp = idx;
        while(tmp<=N){
            arr[tmp] = 1-arr[tmp];
            tmp+=idx;
            
        }
    }
    else{
        int i = 1;
        arr[idx] = 1- arr[idx];
        while(idx-i>0 && idx+i<=N && arr[idx-i] == arr[idx+i]){
             arr[idx-i] = 1-arr[idx-i];
            arr[idx+i] = 1- arr[idx+i];
            i++;
        }
        
    }
}

int main(){
     ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    cin>>M;
    for(int i=0;i<M;i++){
        int gender,index;
        cin>>gender>>index;
        solve(gender,index);
    }
    for(int i=1;i<=N;i++){
        cout<<arr[i]<<" ";
        if(i%20==0)
            cout<<"\n";
    }
    
    
    return 0;
}