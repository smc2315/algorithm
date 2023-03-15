#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int N;
int arr[100000];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int mmin = 1e18;
	int start = 0;
	int end = N - 1;

	int a, b;
	while (start < end) {
		int ssum = arr[start] + arr[end];
		if (ssum == 0) {
			cout << arr[start] << " " << arr[end];
			return 0;
		}
		if (mmin > abs(ssum)) {
			mmin = abs(ssum);
			a = start;
			b = end;
		}
		if (ssum > 0) {
			end--;
		}
		else {
			start++;
		}
	}
	cout << arr[a] << " " << arr[b];
	return 0;
}