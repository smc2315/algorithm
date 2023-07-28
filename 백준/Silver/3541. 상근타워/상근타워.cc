#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int mmin = 1e9;

int calculate(int u, int d) {
    int x = (n*u - 1) / (u+d);
    return (n-x)*u-d*x;
}

int main() {
    cin>>n>>m;

    for(int i=0;i<m;i++) {
        int u,d;
        cin>>u>>d;
        int tmp = calculate(u,d);
        mmin = min(mmin, tmp);
    }
    cout<<mmin;

}