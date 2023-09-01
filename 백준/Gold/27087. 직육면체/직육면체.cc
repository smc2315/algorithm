#include <iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
 
    while(t--) {
        int a, b, c, p;
        
        cin >> a >> b >> c >> p;

        cout << ((((a % p) == 0) + ((b % p) == 0) + ((c % p) == 0)) >= 2)<< "\n";
    }
 
    return 0;
}