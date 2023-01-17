#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int arr[6] = {1,1,2,2,2,8};
    for(int i=0;i<6;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
        
    }
    for(int i=0;i<6;i++){
        cout<<arr[i]-v[i]<<" ";
    }
    return 0;
}