#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define INF 1e9
using namespace std;

int n,m;

int arr[101][101];

void floydWarshall(){

	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == INF) {
				cout << "0" << " ";
			}
			else
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n>>m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;

		}
		arr[i][i] = 0;
	
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(arr[a][b]>c)
			arr[a][b] = c;
	}
	floydWarshall();
	return 0;
}