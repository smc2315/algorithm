#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N,M;
int arr[100001];
vector<pair<int,int>> min_max_tree;

void init(int node, int start, int end) {
    if(start == end) {
        min_max_tree[node] = {arr[start], arr[start]};
        return;
    }
    else {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        min_max_tree[node] = {min(min_max_tree[node * 2].first, min_max_tree[node * 2 + 1].first), max(min_max_tree[node * 2].second, min_max_tree[node * 2 + 1].second)};
        return;
    }

}
pair<int, int> findMinMax(int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return {INT32_MAX, 0};
    }
    else if(left <= start && end <= right) {
        return min_max_tree[node];
    }
    else {
        pair<int, int> l, r;
        l = findMinMax(node * 2, start, (start + end) / 2, left, right);
        r = findMinMax(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
        return {min(l.first, r.first), max(l.second, r.second)};
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int h = (int)ceil(log2(N));
    min_max_tree = vector<pair<int,int>>(1<<(h+1));
    
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init(1, 1, N);

    int left, right;
    pair<int, int> result;
    while(M--) {
        cin >> left >> right;
        result = findMinMax(1, 1, N, left, right);
        cout << result.first << " " << result.second << "\n";
    }
    return 0;
}