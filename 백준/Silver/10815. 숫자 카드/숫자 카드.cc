#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    unordered_map<int,bool> mp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        mp[tmp] = true;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        cout<<mp[tmp]<<" ";
        
    }
    return 0;
    
}