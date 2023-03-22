#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, S;
vector<int> v;
map<int, int> m;
long long cnt;

void right(int mid, int sum) {
    if (mid == N) {
        m[sum]++;
        return;
    }

    right(mid + 1, sum + v[mid]);
    right(mid + 1, sum);
}

void left(int st, int sum) {
    if (st == N / 2) {
        cnt += m[S - sum];
        return;
    }

    left(st + 1, sum + v[st]);
    left(st + 1, sum);
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    right(N / 2, 0);
    left(0, 0);


    if (!S) 
        cout << cnt - 1;
    else 
        cout << cnt;

    return 0;
}