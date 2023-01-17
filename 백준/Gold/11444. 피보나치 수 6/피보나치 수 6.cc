#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long arr[2][2] = { {1,1},{1,0} };
void mul(long long arr1[2][2], long long arr2[2][2]) {
	long long tmp[2][2] = { {0,0},{0,0} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			long long ssum = 0;
			for (int k = 0; k < 2; k++) {
				ssum += (arr1[i][k] * arr2[k][j]) % 1000000007;

			}
			tmp[i][j] = ssum %1000000007;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			arr1[i][j] = tmp[i][j];
		}
	}
}

int main() {

	long long n;
	cin >> n;
	
	n--;
	
	long long result[2][2] = { {1,0},{0,1} };
	while (n>0) {
		//cout << n << endl;
		if (n % 2 == 1) {
			mul(result, arr);
			//cout << arr[0][0] << " " << arr[0][1] << " " << arr[1][0] << " " << arr[1][1]<<endl;
		}
		n /= 2;
		mul(arr, arr);
		//cout << arr[0][0] << " " << arr[0][1] << " " << arr[1][0] << " " << arr[1][1]<<endl;
	}
	
	cout << result[0][0];

}