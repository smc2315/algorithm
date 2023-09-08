#include <iostream>
#include <map>
#include <cstring>

using namespace std;

map<string,int> m;

int main() {
    string s;
    int cnt = 0;
    while(getline(cin,s)) {
        m[s]++;
        cnt++;
    }
    cout<<fixed;
    cout.precision(4);
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << i->first << ' ' << i->second * 100 / (double)cnt << endl;
    }
    return 0;
}