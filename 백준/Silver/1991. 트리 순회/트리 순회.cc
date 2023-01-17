#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
int n;
map<char, pair<char, char>> m;

void front(char c) {

    if (c == '.') {
        return;
    }
    cout << c;
    front(m[c].first);
    front(m[c].second);
    
    
}
void mid(char c) {

    if (c == '.') {
        return;
    }
    
    mid(m[c].first);
    cout << c;
    mid(m[c].second);


}

void back(char c) {

    if (c == '.') {
        return;
    }

    back(m[c].first);
    
    back(m[c].second);
    cout << c;


}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

   
    for (int i = 0; i < n; i++) {
        char node;
        cin >> node;
        
        char a, b;
        cin >> a >> b;

        m.insert(make_pair(node, make_pair(a, b)));
    }
    front('A');
    cout << endl;
    mid('A');
    cout << endl;
    back('A');

    return 0;

   
}