#include <iostream>
#include<cmath>
#include <queue>
#define INF 999999


using namespace std;
int arr[102][102];
int N;

void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int m;
			cin >> m;
			if (m == 0) {
				arr[i][j] = INF;
			}
			else {
				arr[i][j] = m;
			}
		}
	}
	floyd();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << 1 << " ";
			}
		}
		cout << "\n";
	}

	

	return 0;
}