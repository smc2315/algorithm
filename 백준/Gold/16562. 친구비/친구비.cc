#include <iostream>

using namespace std;

int parent[10001];
int price[10001];
bool visited[10001];
int N, M, K;
int total;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void make_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (price[a] > price[b]) 
			parent[a] = b;
		else
			parent[b] = a;
	}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
		parent[i] = i;
	}

	int a, b;
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		make_union(a, b);
	}
	for (int i = 1; i <= N; i++) {
		int tmp = find(i);
		if (!visited[tmp]) {
			total += price[tmp];
			visited[tmp] = true;
		}
	}
	if (K >= total) 
		cout << total;
	else 
		cout << "Oh no";
	return 0;
}