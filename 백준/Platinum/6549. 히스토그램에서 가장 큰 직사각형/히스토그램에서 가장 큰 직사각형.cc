#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int a[100001];
int n;
void init(vector<int> &tree, int node, int start, int end) {
	if(start == end) tree[node] = start; 
	else{
		init(tree, node * 2, start, (start + end) / 2);
		init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
		if(a[tree[node * 2]] <= a[tree[node * 2 + 1]])tree[node] = tree[node * 2];
		else tree[node] = tree[node * 2 + 1];
	} 
	return;
}
int query(vector<int> &tree, int node, int start, int end, int i, int j) {
    if(i > end || j < start) return -1; 
    if(i <= start && end <= j) return tree[node]; 
    int m1 = query(tree, 2*node, start, (start+end)/2, i, j);
    int m2 = query(tree, 2*node+1, (start+end)/2+1, end, i, j);
    if (m1 == -1) return m2; 
    else if (m2 == -1) return m1;
    else {
        if (a[m1] <= a[m2]) return m1;
        else return m2;
    }
}
long long largest(vector<int> &tree, int start, int end) {
    int minIdx = query(tree, 1, 0, n-1, start, end);
    long long area = (long long)(end-start+1)*(long long)a[minIdx];
    if (start <= minIdx-1) {
        area = max(area, largest(tree, start, minIdx-1));
    }
    if (minIdx+1 <= end) {
        area = max(area, largest(tree, minIdx + 1, end));
    }
    return area;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int h = (int)(ceil(log2(n))+1e-9);
        int tree_size = (1 << (h+1));
        vector<int> tree(tree_size);
        init(tree, 1, 0, n-1);
        cout << largest(tree, 0, n-1) << '\n';
    }
    return 0;
}