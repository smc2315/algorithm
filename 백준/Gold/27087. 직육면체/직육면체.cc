#include <iostream>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        int a, b, c, p;
        int cnt = 0;
        
        cin >> a >> b >> c >> p;

        cnt += (!(a % p) ? 1 : 0);
        cnt += (!(b % p) ? 1 : 0);
        cnt += (!(c % p) ? 1 : 0);
        if(cnt >= 2) {
            cout << 1 << endl;
        } 
        else {
            cout << 0 << endl;
        }
    }
 
    return 0;
}