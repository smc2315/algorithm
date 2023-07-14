#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;
vector<pair<int,int>> wins;
int main() {
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
        wins.push_back({0,i+1});
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i].first + v[i].second * v[j].first > v[j].first + v[j].second * v[i].first){
                wins[i].first++;
            }
            else{
                wins[j].first++;
            }
        }
    }

    sort(wins.begin(), wins.end());
    reverse(wins.begin(),wins.end());
    for(int i=0;i<n;i++){
        cout<<wins[i].second<<endl;
    }
}