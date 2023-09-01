#include <iostream>
#include <cstring>

using namespace std;

int n,m;

bool is_contain_duplicate_number(int n) {
    int arr[10];
    for(int i=0;i<10;i++){
        arr[i] = 0;
    }
    string s = to_string(n);
    for(int i=0;i<s.size();i++) {
        if(arr[s[i] - '0'])
            return true;
        arr[s[i] - '0']++;
    }
    return false;
}

int main() {
    while(cin>>n>>m){
        int cnt=0;
        for(int i=n;i<=m;i++){
            if(!is_contain_duplicate_number(i))
                cnt++;
        }
        cout<<cnt<<endl;
    }
}