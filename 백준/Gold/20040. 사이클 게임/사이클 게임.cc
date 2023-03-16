#include <iostream>
#include <string>


using namespace std;

int N, M;
int parent[500001];
void set_parent() {
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y)
		return true;
	if (x > y) {
		parent[y] = x;
	}
	else
		parent[x] = y;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	set_parent();
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		if (merge(a, b)) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
	
	return 0;
}