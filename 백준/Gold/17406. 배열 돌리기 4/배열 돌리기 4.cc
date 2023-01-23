#include<iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
#include <algorithm>

using namespace std;
int N,M,K;
int arr[51][51];
vector<tuple<int, int, int>> v;
bool selected[6];
int res = 1e9;
void move(int a,int b,int c) {
    //cout << a << " " << b << " " << c << endl;
    if (c == 0)
        return;
    int tmp = arr[a - c][b - c];
    for (int i = a - c; i < a + c; i++) {
        //cout << arr[i][b - c] << " " << arr[i + 1][b - c] << endl;
        arr[i][b-c] = arr[i + 1][b-c];
    }
    for (int j = b - c; j < b + c; j++) {
        arr[a + c][j] = arr[a + c][j + 1];
    }
    for (int i = a + c; i > a - c; i--) {
        arr[i][b + c] = arr[i - 1][b + c];
    }
    for (int j = b + c; j > b - c; j--) {
        arr[a - c][j] = arr[a - c][j - 1];
    }
    arr[a - c][b - c + 1] = tmp;
    
    move(a,b,c-1);
    
}
void cal() {
    for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < M; j++) {
                //cout << arr[i][j] << " ";
                sum += arr[i][j];
            }
            //cout << endl;
            res = min(sum, res);
        }
}
void select_order(int n) {
    if (n == K) {
        cal();
        return;
    }
    for (int i = 0; i < K; i++) {
        if (!selected[i]) {
            selected[i] = true;
            int tmp[51][51];
            copy(&arr[0][0], &arr[0][0] + 51*51, &tmp[0][0]);
            move(get<0>(v[i]),get<1>(v[i]),get<2>(v[i]));
            select_order(n + 1);
            copy(&tmp[0][0], &tmp[0][0] + 51*51, &arr[0][0]);
            
            selected[i] = false;
        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_tuple(a-1, b-1, c));
    }
    select_order(0);
    
    
    cout << res << endl;
    return 0;
}