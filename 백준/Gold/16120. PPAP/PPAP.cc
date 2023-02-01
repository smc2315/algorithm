#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    stack<char> stk;
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        tmp += s[i];
        if (tmp.size() > 4)
            tmp = tmp.substr(1);
        stk.push(s[i]);
        //cout << tmp << endl;
        if (tmp == "PPAP") {
            for (int j = 0; j < 4; j++) {
                stk.pop();
            }
            if (!stk.empty()) {
                tmp = stk.top();
            }
            else {
                tmp = "";
            }
            stk.push('P');
            tmp += "P";
        }
    }
    if (stk.size() == 1 && stk.top() == 'P') {
        cout << "PPAP";
        return 0;
    }
    cout << "NP";
    

    return 0;

}