#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include <tuple>

using namespace std;
priority_queue<tuple<int, int, int>> pq;
int N;

int parent[1025];
vector<int> v[1025];
void input() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            pq.push(make_tuple(-tmp, i, j));
        }
    }
}


int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool check_same_parent(int x, int y) {
    if (find(x) == find(y))
        return true;
    return false;
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y)
        parent[y] = x;
}

void kruskal() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (!check_same_parent(get<1>(cur), get<2>(cur))) {
            merge(get<1>(cur), get<2>(cur));
            v[get<1>(cur)].push_back(get<2>(cur));
            v[get<2>(cur)].push_back(get<1>(cur));
        }
    }
}

void output() {
    for (int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end());
        cout << v[i].size() << " ";
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    input();
    kruskal();
    output();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    
    
   
    return 0;

}