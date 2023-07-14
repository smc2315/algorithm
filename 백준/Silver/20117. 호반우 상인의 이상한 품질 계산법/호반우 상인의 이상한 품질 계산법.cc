#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main() {
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    int answer = 0;
    for(int i=0;i<N/2;i++){
            answer+=v[i]*2;
        }
    if(N%2){
        cout<<answer+v[N/2];
    }
    else{
        cout<<answer;
    }
}