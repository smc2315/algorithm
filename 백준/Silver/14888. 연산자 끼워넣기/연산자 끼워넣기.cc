#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int n;
int oper[4] = { 0, };
vector<int> v;
vector<int> order;
int mmax = -1e9;
int mmin = 1e9;

void update() {
    int tmp = v[0];
    int iter = 1;
    for (int i = 0;i < order.size();i++) {
        if (order[i] == 0) {
            tmp += v[iter++];
        }
        else if (order[i] == 1) {
            tmp -= v[iter++];
        }
        else if (order[i] == 2) {
            tmp *= v[iter++];
        }
        else
            tmp /= v[iter++];
    }
    if (tmp > mmax) {
        mmax = tmp;
    }
    if (tmp < mmin) {
        mmin = tmp;
    }
}

void solve(int s) {

    if (s == (n - 1)) {
        update();
        return;
    }
        
    for (int i = 0;i < 4;i++) {
        if (oper[i] != 0) {
            order.push_back(i);
            oper[i]--;
            solve(s + 1);
            oper[i]++;
            order.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        int A;
        cin >> A;
        v.push_back(A);
    }
    for (int i = 0;i < 4;i++) {
        cin >> oper[i];
    }
    solve(0);
    cout << mmax << endl << mmin;
    
    return 0;
}