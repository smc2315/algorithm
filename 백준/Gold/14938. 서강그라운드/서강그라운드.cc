#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define INF 1e9

using namespace std;

int n, m, r;
int graph[101][101];
int item[101];

void floydWarshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		item[i]=t;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			graph[i][j] = INF;
			if (i == j)
				graph[i][j] = 0;
		}
		
	}
	for (int i = 0; i < r; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	floydWarshall();
	int mmax = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] <= m) {
				sum += item[j];
			}
		}
		if (sum > mmax)
			mmax = sum;
	}
	cout << mmax;
	return 0;

}