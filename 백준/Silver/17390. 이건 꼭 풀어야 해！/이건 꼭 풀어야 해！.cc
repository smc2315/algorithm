#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, Q;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    arr.push_back(0);
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    
    for (int i = 1; i <= N; i++) {
        arr[i] += arr[i - 1];
    }
   
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        cout << arr[R] - arr[L - 1] << "\n";
    }
    return 0;
}