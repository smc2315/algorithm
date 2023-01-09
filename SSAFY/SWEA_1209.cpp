#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int arr[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int t = 1; t <= 10; t++) {
        cin >> T;
        int maxW = 0;
        int maxL = 0;

        int sumD1 = 0;
        int sumD2 = 0;
        for (int i = 0; i < 100; i++) {
            int sumW = 0;
            for (int j = 0; j < 100; j++) {
                int tmp;
                cin >> tmp;

                if (i == j) {
                    sumD1 += tmp;
                }
                else if (i == 99 - j) {
                    sumD2 += tmp;
                }
                arr[i][j] = tmp;
                sumW += tmp;
            }
            if (maxW < sumW)
                maxW = sumW;
        }
        for (int j = 0; j < 100; j++) {
            int sumL = 0;
            for (int i = 0; i < 100; i++) {
                sumL += arr[i][j];
            }
            if (sumL > maxL)
                maxL = sumL;
        }
        cout << "#" << t << " ";
        cout << max(max(maxW, maxL), max(sumD1, sumD2))<<endl;
    }
   
    return 0;
}
