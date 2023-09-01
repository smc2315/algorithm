#include <iostream>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        int a, b, c, p;
        
        cin >> a >> b >> c >> p;

        if((!(a % p) ? 1 : 0) + (!(b % p) ? 1 : 0) + (!(c % p) ? 1 : 0) >= 2) {
            cout << 1 << endl;
        } 
        else {
            cout << 0 << endl;
        }
    }
 
    return 0;
}