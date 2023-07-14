#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ssum(10000, vector<int>(10000, 0));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while (t--) {
        int answer = 0;
        int n;
        cin>>n;
        while (n--) {
            int x,y;
            cin>>x>>y;

            for (int i = x; i <= min(x + 10, 9999); i++) {
                for (int j = y; j <= min(y + 10, 9999); j++) {
                    answer = max(answer, ++ssum[i][j]);
                }
            }
        }
        cout << answer << '\n';

        for (int i = 0; i < 10000; i++) {
            for (int j = 0; j < 10000; j++) {
                ssum[i][j] = 0;
            }
        }
    }

    return 0;
}