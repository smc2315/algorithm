#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
int N, M;
int army[100001];
int parent[100001];

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find (parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);

    if (army[a] < army[b]) {
        parent[a] = b;
        army[b] += army[a];
        army[a] = 0;
    }
    else {
        parent[b] = a;
        army[a] += army[b];
        army[b] = 0;
    }
}
void fight(int a,int b) {
    a = find(a);
    b = find(b);

    if (army[a] == army[b]) {
        parent[a] = 0;
        parent[b] = 0;
    }
    else if (army[a] > army[b]) {
        army[a] -= army[b];
        army[b] = 0;
        Union(a, b);
    }
    else {
        army[b] -= army[a];
        army[a] = 0;
        Union(a,b);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <=N; i++)
        parent[i] = i;
    for (int i = 1; i <=N; i++) {
        cin >> army[i];
    }
    int cnt = 1;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) 
            Union(b, c);
        else
            fight(b, c);
        
    }
    vector<int>country;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i == find(i)) {
            sum++;
            country.push_back(army[i]);
        }
    }
    sort(country.begin(), country.end());
    cout << sum << endl;
    for (auto i : country) {
        cout << i << " ";
    }

    return 0;

}