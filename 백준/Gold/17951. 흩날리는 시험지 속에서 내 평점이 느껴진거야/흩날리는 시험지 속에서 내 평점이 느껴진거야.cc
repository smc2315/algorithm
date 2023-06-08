#include <iostream>

using namespace std;

int N, K;
int arr[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int s;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		s += arr[i];
	}

	int pl = 0;
	int pr = s;

	while (pl <= pr) {
		int mid = (pl + pr) / 2;
		int sum = 0, cnt = 0;
		for (int i = 0; i < N; i++) {
			sum += arr[i];
			if (sum >= mid) {
				cnt++;
				sum = 0;
			}
		}

		if (cnt >= K) {
			pl = mid + 1;
		}
		else
			pr = mid - 1;
	}

	cout << pr;
	return 0;
}