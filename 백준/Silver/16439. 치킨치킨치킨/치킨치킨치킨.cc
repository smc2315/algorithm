#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int chicken[30][30];
bool selected[30];
int ans = 0;

int cal_satis() {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        int mmax = 0;
        for (int j = 0; j < M; j++) {
            if (selected[j])
                mmax = max(mmax, chicken[i][j]);
        }
        ret += mmax;
    }
    return ret;
}

void back_track(int cnt,int s) {
    if (cnt == 3) {
        int satis = cal_satis();
        ans = max(ans, satis);
        return;
    }
    for (int i = s; i < M; i++) {
        selected[i] = true;
        back_track(cnt + 1,i+1);
        selected[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> chicken[i][j];
        }
    }
    back_track(0,0);
    cout << ans;
    return 0;
}