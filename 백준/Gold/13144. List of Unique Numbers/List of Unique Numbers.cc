
#include <iostream>
#include <vector>

using namespace std;
bool arr[100001] = { false, };
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a[100001] = { 0, };
	long long ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int j = 0;
	for (int i = 0; i < N; i++) {
		
		 while(j<N){
			if (arr[a[j]]) {
				break;
			}
			arr[a[j]] = true;
			j++;
		}
		ans += j - i;
		arr[a[i]] = false;
	}
	cout << ans;
	return 0;
}