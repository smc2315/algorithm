#include <iostream>
#include <algorithm>

using namespace std;

int N; 
int main(){
    cin >> N;
    int arr[N];
    for (int i=0; i<N; i++)
        cin >> arr[i];

    int ucnt = 0,dcnt = 0 ;

    int uk = 0, dk = 0;

    for (int i=1; i<N; i++) {
        if (arr[i-1] < arr[i]) {
            ucnt++;
            uk = i;
        }
        if (arr[i-1] > arr[i]) {
            dcnt++;
            dk = i;
        }
    }

    if (ucnt > 1 || (ucnt == 1 && !(arr[N-1] >= arr[0]))) {
        uk = -1;
    }

    if (dcnt > 1 || (dcnt == 1 && !(arr[N-1] <= arr[0]))) {
        dk = -1;
    }

    int ans = 0;

    if (uk != -1 && dk != -1)
        ans = min(uk, dk);

    else {
        ans = max(uk, dk);
    }

    cout << ans << endl;

    return 0;
}