#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
int T;

int arr[8][8];
int n;
void rotate() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[n-1-j][i];
        }
        cout << " ";
        for (int j = 0; j < n; j++) {
            cout << arr[n - 1 - i][n - 1 - j];
        }
        cout << " ";
        for (int j = 0; j < n; j++) {
            cout << arr[j][n - 1 - i];
        }
        cout << endl;
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        rotate();
    }
   
    return 0;
}
