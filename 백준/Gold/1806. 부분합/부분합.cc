
#include<iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

using namespace std;

int N, S;
long long arr[100001];
int main(){
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        
        
        arr[i] = arr[i - 1] + tmp;
    }
    int i = 0, j = 1;
    
    int mmin = 1e9;
    while (j <= N) {
        //cout << i << " " << j << endl;
        
        if (arr[j] - arr[i] >= S) {
            mmin = min(mmin, j - i);
            i++;
        }
        else {
            j++;
        }
        
       
    }
    if (mmin == 1e9) {
        cout << 0;
        return 0;
    }
    cout << mmin;
    return 0;
}