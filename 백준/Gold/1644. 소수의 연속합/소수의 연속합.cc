#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
int N;
vector<int> prime;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    vector<bool> v(N + 1, true);
    for (int i = 2; i*i<=N; i++) {
        if (!v[i])
            continue;
        for (int j = i + i; j <= N; j+=i) {
            v[j] = false;
        }
        
    }
    for (int i = 2; i <= N; i++) {
        if (v[i])
            prime.push_back(i);
    }
    
    int i = 0;
    int j = 0;
    int sum = 0;
    int res = 0;
    while (true) {
        if (sum > N) {
            sum -= prime[i++];
        }
        else if (j >= prime.size()) {
            break;
        }
        else
            sum += prime[j++];
        if (sum == N)
            res++;
    }
    cout << res;

    return 0;
}