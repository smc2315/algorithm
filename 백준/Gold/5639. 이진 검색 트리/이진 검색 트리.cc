#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> v;
void postorder(int s,int e) {
    if (s >= e) {
        cout << v[s] << "\n";
        return;
    }
    int root = v[s];
    int tmp=-1;
    for (int i = s+1; i < e; i++) {
        if (v[i] < root) {
            tmp = i;

        }
    }
    if (tmp >= 0) {
        if (s + 1 < tmp + 1) {
            postorder(s + 1, tmp + 1);
        }
        if (tmp + 1 < e) {
            postorder(tmp + 1, e);
        }
    }
    else {
        if (s + 1 < e) {
            postorder(s + 1, e);
        }
    }
    
    cout << root << "\n";

}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp;

    while (cin >> tmp) {
        v.push_back(tmp);
    }
    postorder(0,v.size());
   

    return 0;

   
}