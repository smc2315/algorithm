#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;

int inorder[100001], postorder[100001],froot[100001];


void preorder(int s, int e, int s2, int e2) {
    if (s > e)
        return;
    int root = postorder[e2];
    cout << root << " ";
    int pos = froot[root];
    preorder(s, pos - 1, s2, s2 + (pos - 1 - s));
    preorder(pos + 1, e, s2 + pos - s, e2 - 1);
    
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        froot[inorder[i]] = i;

    }
    for (int i = 0; i < n; i++) {
        
        cin >> postorder[i];

    }
    preorder(0, n - 1, 0, n - 1);
    return 0;

   
}