#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
int N,X;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);

    }
    cin >> X;
    sort(v.begin(), v.end());
    int start = 0;
    int end = N - 1;
    int res = 0;
    while (start < end) {
        if (v[start] + v[end] < X) {
            start++;
        }
        else if (v[start] + v[end] > X) {
            end--;
        }
        else {
            res++;
            start++;
            end--;
        }
    }
    cout << res;
    return 0;
}